--在可用的大厅服务器中选出人数最少的
--此脚本未满足Redis脚本规范，不可在cluster架构下使用
--返回值：
--		没有可用的服务器时返回： INTEGER 0
--		筛选成功时返回：ARRAY [0]IP [1]tcpPort [2]wsPort [3]lobbyID


local serverIDList = redis.call("SMEMBERS", "LobbyServerIDSet")
if #serverIDList == 0 then
	return {} --没有服务器可选择
end
local serverInfoList = {}
for k , v in pairs(serverIDList) do
	local t = redis.call("HMGET", "LobbyServerInfoHash_" .. v, "address", "tcpPort", "wsPort", "active", "connectedCount", "enableInvolveBalance")
	if t[4] ~= "0" and t[6] ~= "0" then
		local s = true
		for k2 , v2 in pairs(t) do
			if v2 == false then
				s = false
				break
			end
		end
		if s then
			t.lobbyID = v
			table.insert(serverInfoList, t)
		end
	end
end
if #serverInfoList == 0 then
	return {} --没有任何服务器的信息是有效的
end
table.sort(serverInfoList, function (a, b)
	return a[5] < b[5]
end)
return { serverInfoList[1][1], serverInfoList[1][2], serverInfoList[1][3], serverInfoList[1]["lobbyID"] } --返回选择好的服务器