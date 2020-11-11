#ifndef __FRAMEWORK_LINKEDMAP_H__
#define __FRAMEWORK_LINKEDMAP_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"

FW_NS_BEGIN


template <class KEY, class VALUE>
class FWLinkedMap
{
	template <class F, class S>
	class FWLinkedMapNode
	{
	public:
		FWLinkedMapNode(F f, S s) :first(f), second(s) {};
		FWLinkedMapNode(const FWLinkedMapNode & other) :first(other.first), second(other.second) {};
		FWLinkedMapNode& operator=(const FWLinkedMapNode & other) = delete;
		//FWLinkedMapNode(FWLinkedMapNode && other) = delete;
		FWLinkedMapNode& operator=(FWLinkedMapNode && other) = delete;
		F first;
		S second;
	};
public:
	FWLinkedMap() :_accessOrder(false) {};
	FWLinkedMap(bool accessOrder) :_accessOrder(accessOrder) {};
	FWLinkedMap(const FWLinkedMap & other) = delete;
	FWLinkedMap& operator=(const FWLinkedMap & other) = delete;
	FWLinkedMap(FWLinkedMap && other) = delete;
	FWLinkedMap& operator=(FWLinkedMap && other) = delete;
	~FWLinkedMap() {};
	
	typedef FWLinkedMapNode<const KEY, VALUE> LmNode;
	typedef typename std::list<LmNode>::iterator Iterator;
	typedef typename std::list<LmNode>::const_iterator Const_Iterator;

	bool Insert(const KEY & k, const VALUE & v)
	{
		if (_mp.find(k) != _mp.end())
			return false;
		_lt.push_back(LmNode(k, v));
		_mp[k] = --(_lt.end());
		return true;
	}

	VALUE & operator[](const KEY & k)
	{
		typename std::map<KEY, Iterator>::iterator it = _mp.find(k);
		if (it != _mp.end())
			return it->second->second;
		_lt.push_back(LmNode(k, VALUE()));
		Iterator it2 = --(_lt.end());
		_mp[k] = it2;
		return it2->second;
	}

	size_t Erase(const KEY & k)
	{
		typename std::map<KEY, Iterator>::iterator it = _mp.find(k);
		if (it == _mp.end())
			return 0;
		_lt.erase(it->second);
		_mp.erase(it);
		return 1;
	}

	size_t Erase(const Iterator & it)
	{
		if (it == this->End())
			return 0;
		size_t r = _mp.erase(it->first);
		_lt.erase(it);
		return r;
	}

	Iterator Find(const KEY & k)
	{
		typename std::map<KEY, Iterator>::iterator it = _mp.find(k);
		if (it == _mp.end())
			return this->End();
		if (_accessOrder && it->second != --(_lt.end()))
		{
			_lt.push_back(*(it->second));
			_lt.erase(it->second);
			it->second = --(_lt.end());
		}
		return it->second;
	}

	Iterator Begin()
	{
		return _lt.begin();
	}

	Iterator End()
	{
		return _lt.end();
	}

	Const_Iterator Begin() const
	{
		return _lt.begin();
	}

	Const_Iterator End() const
	{
		return _lt.end();
	}

	size_t Size() const
	{
#if defined(_DEBUG)
		if (_lt.size() != _mp.size())
		{
			assert(false);
		}
#endif
		return _lt.size();
	}

	void Clear()
	{
		_lt.clear();
		_mp.clear();
	}

private:
	bool					_accessOrder;
	std::map<KEY, Iterator>	_mp;
	std::list<LmNode>		_lt;
};


FW_NS_END


#endif //!__FRAMEWORK_LINKEDMAP_H__