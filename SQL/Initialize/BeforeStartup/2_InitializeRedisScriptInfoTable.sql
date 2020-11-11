/*
Redis脚本sha1表
*/
DROP TABLE IF EXISTS `redis_script_info`;
CREATE TABLE IF NOT EXISTS `redis_script_info`(
	`filename` VARCHAR(256) NOT NULL COMMENT '脚本文件名',
	`sha1` VARCHAR(128) NOT NULL COMMENT 'sha1字符串',
	PRIMARY KEY (`fileName`)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin ROW_FORMAT=DYNAMIC;