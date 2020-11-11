
/*
想清理几号大厅服就改成几号
*/
#UPDATE `player_info` SET `lobbyServerID` = 0 WHERE `lobbyServerID` = 99;

/*
清理所有
*/
#UPDATE `player_info` SET `lobbyServerID` = 0;