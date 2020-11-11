
/*
想清理几号大厅服就改成几号
*/
#UPDATE `player_info` SET `logicalServerID` = 0, `logicalServerStationID` = 0 WHERE `logicalServerID` = 99999;

/*
清理所有
*/
#UPDATE `player_info` SET `logicalServerID` = 0, `logicalServerStationID` = 0;