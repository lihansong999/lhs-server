#ifndef __FRAMEWORK_LINKEDSET_H__
#define __FRAMEWORK_LINKEDSET_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"

FW_NS_BEGIN


template <class VALUE>
class FWLinkedSet
{
public:
	FWLinkedSet() :_accessOrder(false) {};
	FWLinkedSet(bool accessOrder) :_accessOrder(accessOrder) {};
	FWLinkedSet(const FWLinkedSet & other) = delete;
	FWLinkedSet& operator=(const FWLinkedSet & other) = delete;
	FWLinkedSet(FWLinkedSet && other) = delete;
	FWLinkedSet& operator=(FWLinkedSet && other) = delete;
	~FWLinkedSet() {};

	typedef typename std::list<VALUE>::const_iterator Iterator;
	
	bool Insert(const VALUE & v)
	{
		if (_mp.find(v) != _mp.end())
			return false;
		_lt.push_back(v);
		_mp[v] = --(_lt.end());
		return true;
	}

	size_t Erase(const VALUE & v)
	{
		typename std::map<VALUE, Iterator>::iterator it = _mp.find(v);
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
		size_t r = _mp.erase(*it);
		_lt.erase(it);
		return r;
	}

	Iterator Find(const VALUE & v)
	{
		typename std::map<VALUE, Iterator>::iterator it = _mp.find(v);
		if (it == _mp.end())
			return this->End();
		if (_accessOrder && it->second != --(_lt.end()))
		{
			_lt.erase(it->second);
			_lt.push_back(it->first);
			it->second = --(_lt.end());
		}
		return it->second;
	}

	Iterator Begin() const
	{
		return _lt.begin();
	}

	Iterator End() const
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
	bool						_accessOrder;
	std::map<VALUE, Iterator>	_mp;
	std::list<VALUE>			_lt;
};


FW_NS_END


#endif //!__FRAMEWORK_LINKEDSET_H__