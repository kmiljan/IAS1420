CREATE TABLE `<tableName>` ( `id` int NOT NULL AUTO_INCREMENT,
`humidity` float NOT NULL,
`temperature` float NOT NULL,
`Requestedventpowerlevel` float NOT NULL,
`Humiditychange` float NOT NULL,
`Humiditybaseline` float NOT NULL,
`Temperaturechange` float NOT NULL,
`Temperaturebaseline` float NOT NULL,
`Outputenabled` float NOT NULL,
`StateID` TEXT NOT NULL,
`date` timestamp NULL DEFAULT CURRENT_TIMESTAMP, 
PRIMARY KEY (`id`) )
ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;