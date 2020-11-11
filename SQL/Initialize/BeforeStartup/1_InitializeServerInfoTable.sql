/*
大厅服表
*/
DROP TABLE IF EXISTS `lobby_server_info`;
CREATE TABLE IF NOT EXISTS `lobby_server_info`(
	`lobbyID` INT(11) NOT NULL COMMENT '大厅服ID，必须大于0',
	`address` VARCHAR(512) NOT NULL COMMENT 'IP地址',
	`tcpPort` INT(11) NOT NULL COMMENT 'TCP端口',
	`wsPort` INT(11) NOT NULL COMMENT 'WebSocket端口',
	`testAddress` VARCHAR(512) NOT NULL COMMENT '测试IP地址',
	`tcpTestPort` INT(11) NOT NULL COMMENT 'TCP测试端口',
	`wsTestPort` INT(11) NOT NULL COMMENT 'WebSocket测试端口',
	PRIMARY KEY (`lobbyID`),
	UNIQUE KEY (`address`,`tcpPort`),
	UNIQUE KEY (`address`,`wsPort`),
	UNIQUE KEY (`testAddress`,`tcpTestPort`),
	UNIQUE KEY (`testAddress`,`wsTestPort`)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin ROW_FORMAT=DYNAMIC;

/*
大厅服表插入触发器
*/
DROP TRIGGER IF EXISTS `on_insert_lobby_server_info`;
CREATE TRIGGER `on_insert_lobby_server_info` BEFORE INSERT ON `lobby_server_info` FOR EACH ROW
BEGIN
	IF NEW.testAddress IS NULL THEN
		SET NEW.testAddress = NEW.address;
	END IF;
	IF NEW.tcpTestPort IS NULL THEN
		SET NEW.tcpTestPort = NEW.tcpPort;
	END IF;
	IF NEW.wsTestPort IS NULL THEN
		SET NEW.wsTestPort = NEW.wsPort;
	END IF;
END;

/*
逻辑服表
*/
DROP TABLE IF EXISTS `logical_server_info`;
CREATE TABLE IF NOT EXISTS `logical_server_info`(
	`logicalID` INT(11) NOT NULL COMMENT '逻辑服ID，必须大于0',
	`address` VARCHAR(512) NOT NULL COMMENT 'IP地址',
	`tcpPort` INT(11) NOT NULL COMMENT 'TCP端口',
	`wsPort` INT(11) NOT NULL COMMENT 'WebSocket端口',
	`testAddress` VARCHAR(512) NOT NULL COMMENT '测试IP地址',
	`tcpTestPort` INT(11) NOT NULL COMMENT 'TCP测试端口',
	`wsTestPort` INT(11) NOT NULL COMMENT 'WebSocket测试端口',
	PRIMARY KEY (`logicalID`),
	UNIQUE KEY (`address`,`tcpPort`),
	UNIQUE KEY (`address`,`wsPort`),
	UNIQUE KEY (`testAddress`,`tcpTestPort`),
	UNIQUE KEY (`testAddress`,`wsTestPort`)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin ROW_FORMAT=DYNAMIC;

/*
逻辑服表插入触发器
*/
DROP TRIGGER IF EXISTS `on_insert_logical_server_info`;
CREATE TRIGGER `on_insert_logical_server_info` BEFORE INSERT ON `logical_server_info` FOR EACH ROW
BEGIN
	IF NEW.testAddress IS NULL THEN
		SET NEW.testAddress = NEW.address;
	END IF;
	IF NEW.tcpTestPort IS NULL THEN
		SET NEW.tcpTestPort = NEW.tcpPort;
	END IF;
	IF NEW.wsTestPort IS NULL THEN
		SET NEW.wsTestPort = NEW.wsPort;
	END IF;
END;

/*
一条一条地插入大厅服信息
*/
INSERT INTO `lobby_server_info`(`lobbyID`, `address`, `tcpPort`, `wsPort`) VALUES (1, '127.0.0.1', '9101', '9401');
INSERT INTO `lobby_server_info`(`lobbyID`, `address`, `tcpPort`, `wsPort`) VALUES (2, '127.0.0.1', '9102', '9402');

/*
一条一条地插入逻辑服信息
*/
INSERT INTO `logical_server_info`(`logicalID`, `address`, `tcpPort`, `wsPort`) VALUES (1, '127.0.0.1', '9201', '9501');
INSERT INTO `logical_server_info`(`logicalID`, `address`, `tcpPort`, `wsPort`) VALUES (2, '127.0.0.1', '9202', '9502');

