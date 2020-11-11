/*
账号表
*/
DROP TABLE IF EXISTS `account_info`;
CREATE TABLE IF NOT EXISTS `account_info`(
	`account` VARCHAR(384) NOT NULL COMMENT '账号或唯一码的Hash',
	`pwd` VARCHAR(384) NOT NULL COMMENT '密码或唯一码',
	`phone` VARCHAR(32) NOT NULL DEFAULT '' COMMENT '手机号码',
	`email` VARCHAR(100) NOT NULL DEFAULT '' COMMENT '电子邮箱',
	PRIMARY KEY (`account`)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin ROW_FORMAT=DYNAMIC;

/*
玩家表
*/
DROP TABLE IF EXISTS `player_info`;
CREATE TABLE IF NOT EXISTS `player_info`(
	`playerID` BIGINT(20) NOT NULL AUTO_INCREMENT COMMENT '玩家ID',
	`account` VARCHAR(384) NOT NULL COMMENT '账号',
	`nickname` VARCHAR(160) NOT NULL DEFAULT '' COMMENT '昵称，限制20个字的UTF8编码，再Base64Encode，最终最大长度为20*6/3*4',
	`sex` TINYINT(4) NOT NULL DEFAULT 0 COMMENT '性别',
	`golds` BIGINT(20) NOT NULL DEFAULT 0 COMMENT '金币',
	`diamonds` BIGINT(20) NOT NULL DEFAULT 0 COMMENT '钻石',
	`dynaPwd` VARCHAR(32) NOT NULL DEFAULT '' COMMENT '动态密码，用于逻辑服登录验证',
	`lobbyServerID` INT(11) NOT NULL DEFAULT 0 COMMENT '当前连接的大厅服ID，只要大于0就是在线状态',
	`lobbyServerNetType` INT(11) NOT NULL DEFAULT 0 COMMENT '大厅服网络类型',
	`lobbyServerNetIndex` INT(10) UNSIGNED NOT NULL DEFAULT 0 COMMENT '大厅服网络Index',
	`lobbyServerNetActivityID` BIGINT(20) NOT NULL DEFAULT 0 COMMENT '大厅服网络活动ID',
	`logicalServerID` INT(11) NOT NULL DEFAULT 0 COMMENT '当前连接的逻辑服ID，只要大于0就是游戏进行中的状态。注意：游戏进行中(logicalServerStationID>0)时出现套接字断线此值不会被清0',
	`logicalServerNetType` INT(11) NOT NULL DEFAULT 0 COMMENT '逻辑服网络类型',
	`logicalServerNetIndex` INT(10) UNSIGNED NOT NULL DEFAULT 0 COMMENT '逻辑服网络Index',
	`logicalServerNetActivityID` BIGINT(20) NOT NULL DEFAULT 0 COMMENT '逻辑服网络活动ID',
	`logicalServerStationID` INT(11) NOT NULL DEFAULT 0 COMMENT '当前逻辑站ID，通过logicalServerID加logicalServerStationID可以唯一确定在哪一个游戏中',
	PRIMARY KEY (`playerID`),
	UNIQUE KEY `account` (`account`)
)ENGINE=InnoDB AUTO_INCREMENT=1000000 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin ROW_FORMAT=DYNAMIC;

/*
注册账号存储过程（账号密码注册）
*/
DROP PROCEDURE IF EXISTS `register_new_account`;
CREATE PROCEDURE `register_new_account`(IN `acc` VARCHAR(72), IN `pin` VARCHAR(72), IN `nickname_in` VARCHAR(160), IN `sex_in` TINYINT(4))
BEGIN
	DECLARE	`ret` INT DEFAULT 0;
	DECLARE	`accLen` INT DEFAULT 0;
	DECLARE	`accCharLen` INT DEFAULT 0;
	DECLARE	`pinLen` INT DEFAULT 0;
	DECLARE	`pinCharLen` INT DEFAULT 0;
	DECLARE	`tempCount` INT DEFAULT 0;

	`LP`:LOOP

		IF `acc` IS NULL OR `pin` IS NULL THEN
			#账号或密码为NULL
			SET `ret` = -1;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT LENGTH(`acc`) INTO `accLen`;
		SELECT CHAR_LENGTH(`acc`) INTO `accCharLen`;
		IF `accLen` < 6 OR `accLen` > 12 OR `accLen` != `accCharLen` THEN
			#账号不合法
			SET `ret` = -2;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT LENGTH(`pin`) INTO `pinLen`;
		SELECT CHAR_LENGTH(`pin`) INTO `pinCharLen`;
		IF `pinLen` < 6 OR `pinLen` > 12 OR `pinLen` != `pinCharLen` THEN
			#密码不合法
			SET `ret` = -3;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		IF `nickname_in` IS NULL OR `sex_in` IS NULL THEN
			#nickname或sex为NULL
			SET `ret` = -4;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT COUNT(`account`) INTO `tempCount` FROM `account_info` WHERE `account` = `acc`;
		IF `tempCount` != 0 THEN
			#账号已存在
			SET `ret` = -5;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		INSERT IGNORE INTO `account_info`(`account`, `pwd`) VALUES (`acc`, `pin`);
		SELECT ROW_COUNT() INTO `tempCount`;
		IF `tempCount` != 1 THEN
			#插入失败，并发执行时有可能另一个会话抢先插入了相同的账号
			SET `ret` = -6;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;
		
		UPDATE `player_info` SET `nickname` = `nickname_in`, `sex` = `sex_in` WHERE `account` = `acc`;
		SET `ret` = 0;
		SELECT `ret`;
		LEAVE `LP`;
	END LOOP;
END;

/*
注册账号存储过程（unionid注册）
*/
DROP PROCEDURE IF EXISTS `register_new_account_unionid`;
CREATE PROCEDURE `register_new_account_unionid`(IN `hash` VARCHAR(384), IN `unionid` VARCHAR(384), IN `nickname_in` VARCHAR(160), IN `sex_in` TINYINT(4))
BEGIN
	DECLARE	`ret` INT DEFAULT 0;
	DECLARE	`hashLen` INT DEFAULT 0;
	DECLARE	`hashCharLen` INT DEFAULT 0;
	DECLARE	`unionidLen` INT DEFAULT 0;
	DECLARE	`unionidCharLen` INT DEFAULT 0;
	DECLARE	`tempCount` INT DEFAULT 0;
	
	`LP`:LOOP

		IF `hash` IS NULL OR `unionid` IS NULL THEN
			#hash或unionid为NULL
			SET `ret` = -1;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT LENGTH(`hash`) INTO `hashLen`;
		SELECT CHAR_LENGTH(`hash`) INTO `hashCharLen`;
		IF `hashLen` != 64 OR `hashLen` != `hashCharLen` THEN
			#hash不合法
			SET `ret` = -2;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT LENGTH(`unionid`) INTO `unionidLen`;
		SELECT CHAR_LENGTH(`unionid`) INTO `unionidCharLen`;
		IF `unionidLen` < 6 OR `unionidLen` > 64 OR `unionidLen` != `unionidCharLen` THEN
			#unionid不合法
			SET `ret` = -3;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		IF `nickname_in` IS NULL OR `sex_in` IS NULL THEN
			#nickname或sex为NULL
			SET `ret` = -4;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT COUNT(`account`) INTO `tempCount` FROM `account_info` WHERE `account` = `hash`;
		IF `tempCount` != 0 THEN
			#Hash已存在（由于唯一码可重复注册，所以返回成功）
			UPDATE `player_info` SET `nickname` = `nickname_in`, `sex` = `sex_in` WHERE `account` = `hash`;
			SET `ret` = 0;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		INSERT IGNORE INTO `account_info`(`account`, `pwd`) VALUES (`hash`, `unionid`);
		SELECT ROW_COUNT() INTO `tempCount`;
		IF `tempCount` != 1 THEN
			#插入失败，并发执行时有可能另一个会话抢先插入了相同的账号
			SET `ret` = -6;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;
		
		UPDATE `player_info` SET `nickname` = `nickname_in`, `sex` = `sex_in` WHERE `account` = `hash`;
		SET `ret` = 0;
		SELECT `ret`;
		LEAVE `LP`;
	END LOOP;
END;

/*
登录存储过程（账号密码登录）
*/
DROP PROCEDURE IF EXISTS `login_account`;
CREATE PROCEDURE `login_account`(IN `acc` VARCHAR(72), IN `pin` VARCHAR(72), IN `lid` INT(11), IN `ltp` INT(11), IN `lsi` INT(10) UNSIGNED, IN `lsa` BIGINT(20))
BEGIN
	DECLARE	`ret` INT DEFAULT 0;
	DECLARE	`accLen` INT DEFAULT 0;
	DECLARE	`accCharLen` INT DEFAULT 0;
	DECLARE	`pinLen` INT DEFAULT 0;
	DECLARE	`pinCharLen` INT DEFAULT 0;
	DECLARE	`tempCount` INT DEFAULT 0;
	DECLARE	`dp` VARCHAR(32) DEFAULT '';

	`LP`:LOOP

		IF `acc` IS NULL OR `pin` IS NULL THEN
			#账号或密码为NULL
			SET `ret` = -1;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT LENGTH(`acc`) INTO `accLen`;
		SELECT CHAR_LENGTH(`acc`) INTO `accCharLen`;
		IF `accLen` < 6 OR `accLen` > 12 OR `accLen` != `accCharLen` THEN
			#账号不合法
			SET `ret` = -2;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT LENGTH(`pin`) INTO `pinLen`;
		SELECT CHAR_LENGTH(`pin`) INTO `pinCharLen`;
		IF `pinLen` < 6 OR `pinLen` > 12 OR `pinLen` != `pinCharLen` THEN
			#密码不合法
			SET `ret` = -3;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT COUNT(`account`) INTO `tempCount` FROM `account_info` WHERE `account` = `acc` AND `pwd` = `pin`;
		IF `tempCount` != 1 THEN
			#账号或密码错误
			SET `ret` = -4;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;
		
		SELECT MD5(UUID_SHORT()) INTO `dp`;

		START TRANSACTION;
			SELECT `playerID`, `dp` as `dynaPwd`, `logicalServerID`, `lobbyServerID` as `last_lobbyServerID`, `lobbyServerNetType` as `last_lobbyServerNetType`, `lobbyServerNetIndex` as `last_lobbyServerNetIndex`, `lobbyServerNetActivityID` as `last_lobbyServerNetActivityID` FROM `player_info` WHERE `account` = `acc` FOR UPDATE;
			UPDATE `player_info` SET `lobbyServerID` = `lid`, `lobbyServerNetType` = `ltp`, `lobbyServerNetIndex` = `lsi`, `lobbyServerNetActivityID` = `lsa`, `dynaPwd` = `dp` WHERE `account` = `acc`;
		COMMIT;
		
		LEAVE `LP`;
	END LOOP;
END;

/*
登录存储过程（unionid登录）
*/
DROP PROCEDURE IF EXISTS `login_account_unionid`;
CREATE PROCEDURE `login_account_unionid`(IN `hash` VARCHAR(384), IN `unionid` VARCHAR(384), IN `lid` INT(11), IN `ltp` INT(11), IN `lsi` INT(10) UNSIGNED, IN `lsa` BIGINT(20))
BEGIN
	DECLARE	`ret` INT DEFAULT 0;
	DECLARE	`hashLen` INT DEFAULT 0;
	DECLARE	`hashCharLen` INT DEFAULT 0;
	DECLARE	`unionidLen` INT DEFAULT 0;
	DECLARE	`unionidCharLen` INT DEFAULT 0;
	DECLARE	`tempCount` INT DEFAULT 0;
	DECLARE	`dp` VARCHAR(32) DEFAULT '';
	
	`LP`:LOOP

		IF `hash` IS NULL OR `unionid` IS NULL THEN
			#hash或unionid为NULL
			SET `ret` = -1;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT LENGTH(`hash`) INTO `hashLen`;
		SELECT CHAR_LENGTH(`hash`) INTO `hashCharLen`;
		IF `hashLen` != 64 OR `hashLen` != `hashCharLen` THEN
			#hash不合法
			SET `ret` = -2;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT LENGTH(`unionid`) INTO `unionidLen`;
		SELECT CHAR_LENGTH(`unionid`) INTO `unionidCharLen`;
		IF `unionidLen` < 6 OR `unionidLen` > 64 OR `unionidLen` != `unionidCharLen` THEN
			#unionid不合法
			SET `ret` = -3;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT COUNT(`account`) INTO `tempCount` FROM `account_info` WHERE `account` = `hash` AND `pwd` = `unionid`;
		IF `tempCount` != 1 THEN
			#unionid错误
			SET `ret` = -4;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;
		
		SELECT MD5(UUID_SHORT()) INTO `dp`;
		
		START TRANSACTION;
			SELECT `playerID`, `dp` as `dynaPwd`, `logicalServerID`, `lobbyServerID` as `last_lobbyServerID`, `lobbyServerNetType` as `last_lobbyServerNetType`, `lobbyServerNetIndex` as `last_lobbyServerNetIndex`, `lobbyServerNetActivityID` as `last_lobbyServerNetActivityID` FROM `player_info` WHERE `account` = `hash` FOR UPDATE;
			UPDATE `player_info` SET `lobbyServerID` = `lid`, `lobbyServerNetType` = `ltp`, `lobbyServerNetIndex` = `lsi`, `lobbyServerNetActivityID` = `lsa`, `dynaPwd` = `dp` WHERE `account` = `hash`;
		COMMIT;
		
		LEAVE `LP`;
	END LOOP;
END;

/*
逻辑服登录存储过程（逻辑服登录）
*/
DROP PROCEDURE IF EXISTS `login_logical`;
CREATE PROCEDURE `login_logical`(in `pid` BIGINT(20), IN `dp` VARCHAR(32), IN `lid` INT(11), IN `ltp` INT(11), IN `lsi` INT(10) UNSIGNED, IN `lsa` BIGINT(20))
BEGIN
	DECLARE	`ret` INT DEFAULT 0;
	DECLARE	`dpLen` INT DEFAULT 0;
	DECLARE	`dpCharLen` INT DEFAULT 0;
	DECLARE	`lastLogicalID` INT DEFAULT -1;
	
	`LP`:LOOP

		IF `pid` IS NULL OR `dp` IS NULL THEN
			#pid或dp为NULL
			SET `ret` = -1;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT LENGTH(`dp`) INTO `dpLen`;
		SELECT CHAR_LENGTH(`dp`) INTO `dpCharLen`;
		IF `dpLen` != 32 OR `dpLen` != `dpCharLen` THEN
			#dp不合法
			SET `ret` = -2;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;

		SELECT `logicalServerID` INTO `lastLogicalID` FROM `player_info` WHERE `playerID` = `pid` AND `dynaPwd` = `dp`;
		IF `lastLogicalID` = -1 THEN
			#dp错误
			SET `ret` = -3;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;
		IF `lastLogicalID` != 0 AND `lastLogicalID` != `lid` THEN
			#已在其他逻辑服登录
			SET `ret` = -4;
			SELECT `ret`;
			LEAVE `LP`;
		END IF;
		
		START TRANSACTION;
			SELECT `logicalServerID` as `last_logicalServerID`, `logicalServerStationID` FROM `player_info` WHERE `playerID` = `pid` FOR UPDATE;
			UPDATE `player_info` SET `logicalServerID` = `lid`, `logicalServerNetType` = `ltp`, `logicalServerNetIndex` = `lsi`, `logicalServerNetActivityID` = `lsa` WHERE `playerID` = `pid`;
		COMMIT;
		
		LEAVE `LP`;
	END LOOP;
END;

/*
注册账号插入触发器
*/
DROP TRIGGER IF EXISTS `on_insert_account_info`;
CREATE TRIGGER `on_insert_account_info` AFTER INSERT ON `account_info` FOR EACH ROW
BEGIN
	#DECLARE	`tempCount` INT DEFAULT 0;
	#INSERT IGNORE INTO `player_info`(`account`) VALUES (NEW.account);
	#SELECT ROW_COUNT() INTO `tempCount`;
	#IF `tempCount` != 1 THEN
	#	#插入失败
	#	SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Insert player_info failed';
	#END IF;
	INSERT INTO `player_info`(`account`) VALUES (NEW.account);
END;

/*
账号表与玩家表的组合视图
*/
DROP VIEW IF EXISTS `account_and_player_info`;
CREATE VIEW `account_and_player_info` 
	AS SELECT playerID, `account_info`.account AS account, pwd, nickname, phone, email 
	FROM `account_info` INNER JOIN `player_info` ON `account_info`.account = `player_info`.account 
	ORDER BY playerID;