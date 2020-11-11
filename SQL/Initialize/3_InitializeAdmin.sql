/*
管理员表
*/
DROP TABLE IF EXISTS `admin_info`;
CREATE TABLE IF NOT EXISTS `admin_info`(
	`account` VARCHAR(384) NOT NULL COMMENT '账号',
	`pwd` VARCHAR(384) NOT NULL COMMENT '密码',
	`name` VARCHAR(120) NOT NULL COMMENT '昵称，限制20个字的UTF8编码',
	PRIMARY KEY (`account`)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin ROW_FORMAT=DYNAMIC;

/*
一条一条地插入管理员账号信息
*/
INSERT INTO `admin_info`(`account`, `name`, `pwd`) VALUES ('lihansong', '李寒松', '123654');