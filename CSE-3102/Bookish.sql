-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Sep 21, 2024 at 06:52 PM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.2.4
SET
  SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";

START TRANSACTION;

SET
  time_zone = "+00:00";

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;

/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;

/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;

/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `Bookish`
--
-- --------------------------------------------------------
--
-- Table structure for table `Author`
--
CREATE TABLE
  `Author` (
    `Author_ID` int (11) NOT NULL,
    `Author_Name` varchar(255) NOT NULL,
    `Birth_Year` int (11) DEFAULT NULL,
    `No_Of_Books` int (11) DEFAULT NULL,
    `No_Of_Awards` int (11) DEFAULT NULL
  ) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_general_ci;

--
-- Dumping data for table `Author`
--
INSERT INTO
  `Author` (
    `Author_ID`,
    `Author_Name`,
    `Birth_Year`,
    `No_Of_Books`,
    `No_Of_Awards`
  )
VALUES
  (1, 'Rabindranath Thakur', 1861, 171, 50),
  (2, 'Zahir Raihan', 1935, 8, 5),
  (3, 'Satyajit Ray', 1921, 145, 30),
  (4, 'Sir Arthur Conan Doyle', 1859, 15, 12),
  (5, 'Anthony Mascarenhas', 1928, 3, NULL),
  (6, 'Jahanara Imam', 1929, 25, 10),
  (7, 'Sufia Kamal', 1911, 10, 3),
  (8, 'Robert Frost', 1874, NULL, NULL);

-- --------------------------------------------------------
--
-- Table structure for table `Author_Book_Relationship`
--
CREATE TABLE
  `Author_Book_Relationship` (
    `Book_No` int (11) NOT NULL,
    `Author_ID` int (11) NOT NULL
  ) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_general_ci;

--
-- Dumping data for table `Author_Book_Relationship`
--
INSERT INTO
  `Author_Book_Relationship` (`Book_No`, `Author_ID`)
VALUES
  (1, 1),
  (2, 1),
  (3, 1),
  (4, 1),
  (5, 1),
  (6, 2),
  (7, 2),
  (8, 2),
  (9, 3),
  (10, 3),
  (11, 3),
  (12, 3),
  (13, 4),
  (14, 4),
  (15, 5),
  (16, 6),
  (17, 7),
  (18, 7),
  (19, 8);

-- --------------------------------------------------------
--
-- Table structure for table `Book`
--
CREATE TABLE
  `Book` (
    `Book_No` int (11) NOT NULL,
    `Book_Name` varchar(255) NOT NULL,
    `Genre` varchar(100) DEFAULT NULL,
    `Language` varchar(100) DEFAULT NULL
  ) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_general_ci;

--
-- Dumping data for table `Book`
--
INSERT INTO
  `Book` (`Book_No`, `Book_Name`, `Genre`, `Language`)
VALUES
  (1, 'Shesher Kobita', 'Drama', 'Bangla'),
  (2, 'Noukadubi', 'Drama', 'Bangla'),
  (3, 'GolpoGuccho', 'Short Stories', 'Bangla'),
  (4, 'Chokher Bali', 'Drama', 'Bangla'),
  (5, 'Gitanjali', 'Poetry', 'Bangla'),
  (6, 'Hajar Bochor Dhore', 'Drama', 'Bangla'),
  (7, 'Borof Gola Nodi', 'Drama', 'Bangla'),
  (8, 'Shesh Bikeler Meye', 'Drama', 'Bangla'),
  (9, 'Shonku Samagra', 'Science Fiction', 'Bangla'),
  (10, 'Golpo 101', 'Short Stories', 'Bangla'),
  (11, 'Hottyapuri', 'Detective', 'Bangla'),
  (12, 'Chinnomostar Ovishap', 'Detective', 'Bangla'),
  (13, 'A Study in Scarlet', 'Detective', 'English'),
  (
    14,
    'The Case-book of Sherlock Holmes',
    'Detective',
    'English'
  ),
  (
    15,
    'Bangladesh: A Legacy of Blood',
    'History',
    'English'
  ),
  (16, 'Ekattorer Dinguli', 'History', 'Bangla'),
  (17, 'Ekattorer Diary', 'History', 'Bangla'),
  (18, 'Kobita Somogro', 'Poetry', 'Bangla'),
  (19, 'Mountain Interval', 'Poetry', 'English');

-- --------------------------------------------------------
--
-- Table structure for table `Book_Character_Relationship`
--
CREATE TABLE
  `Book_Character_Relationship` (
    `Character_ID` int (11) NOT NULL,
    `Book_No` int (11) NOT NULL
  ) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_general_ci;

--
-- Dumping data for table `Book_Character_Relationship`
--
INSERT INTO
  `Book_Character_Relationship` (`Character_ID`, `Book_No`)
VALUES
  (1, 1),
  (2, 1),
  (3, 1),
  (4, 2),
  (5, 2),
  (6, 2),
  (7, 2),
  (8, 3),
  (9, 3),
  (10, 3),
  (11, 3),
  (12, 3),
  (13, 4),
  (14, 4),
  (15, 4),
  (16, 6),
  (17, 6),
  (18, 6),
  (19, 7),
  (20, 7),
  (21, 8),
  (22, 8),
  (23, 9),
  (24, 9),
  (25, 9),
  (26, 10),
  (27, 10),
  (28, 10),
  (29, 10),
  (30, 11),
  (30, 12),
  (31, 11),
  (31, 12),
  (32, 11),
  (32, 12),
  (33, 11),
  (34, 12),
  (35, 13),
  (35, 14),
  (36, 13),
  (36, 14),
  (37, 13),
  (38, 14),
  (39, 14),
  (40, 16),
  (41, 16);

-- --------------------------------------------------------
--
-- Table structure for table `Characters`
--
CREATE TABLE
  `Characters` (
    `Character_ID` int (11) NOT NULL,
    `Character_Name` varchar(255) NOT NULL,
    `Age` int (11) DEFAULT NULL
  ) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_general_ci;

--
-- Dumping data for table `Characters`
--
INSERT INTO
  `Characters` (`Character_ID`, `Character_Name`, `Age`)
VALUES
  (1, 'Amit Ray', 26),
  (2, 'KetakI', 23),
  (3, 'Labanya', 20),
  (4, 'Ramesh', 27),
  (5, 'Hemnalini', 24),
  (6, 'Nalinaksha', 30),
  (7, 'Kamala', 20),
  (8, 'Nirupoma', 15),
  (9, 'Postmaster', 24),
  (10, 'Ratan', 10),
  (11, 'Fotik', 10),
  (12, 'Kadombini', 18),
  (13, 'Mahendra', 25),
  (14, 'Binodini', 15),
  (15, 'Bihari', 23),
  (16, 'Tuni', 18),
  (17, 'Montu', 20),
  (18, 'Mokbul', 49),
  (19, 'Moriyom', 23),
  (20, 'Mahmud', 28),
  (21, 'Kashed', 27),
  (22, 'Jahanara', 24),
  (23, 'Professor Shonku', 59),
  (24, 'Nokur Chandra Biswas', 49),
  (25, 'Abinash Chandra Majumdar', 53),
  (26, 'Tarini Charan Banerjee', 65),
  (27, 'Nyapla', 11),
  (28, 'Bonku Babu', 49),
  (29, 'Professor Hijibijbij', NULL),
  (30, 'Feluda', 21),
  (31, 'Jotayu', 48),
  (32, 'Topshe', 16),
  (33, 'Lakshman Bhattacharya', 35),
  (34, 'Mahesh Choudhury', 70),
  (35, 'Sherlock Holmes', 30),
  (36, 'Dr. Watson', 32),
  (37, 'Brigham Young', 33),
  (38, 'Adelbert Gruner', 35),
  (39, 'Grace Dunbar', 27),
  (40, 'Rumi', 21),
  (41, 'Sharif', 40);

-- --------------------------------------------------------
--
-- Table structure for table `Publisher`
--
CREATE TABLE
  `Publisher` (
    `Publisher_ID` int (11) NOT NULL,
    `Publisher_Name` varchar(255) NOT NULL,
    `Country` varchar(100) DEFAULT NULL
  ) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_general_ci;

--
-- Dumping data for table `Publisher`
--
INSERT INTO
  `Publisher` (`Publisher_ID`, `Publisher_Name`, `Country`)
VALUES
  (1, 'Baatighar', 'Bangladesh'),
  (2, 'Suchoyoni Publishers', 'Bangladesh'),
  (3, 'Bishwasahitto Vobon', 'Bangladesh'),
  (4, 'The Sky Publishers', 'Bangladesh'),
  (5, 'Muktodhara', 'Bangladesh'),
  (6, 'Dip Prokason', 'India'),
  (7, 'Kalantor Prokashani', 'Bangladesh'),
  (8, 'Anupom Prokashani', 'Bangladesh'),
  (9, 'Ananda Publishers', 'India'),
  (10, 'Nowroze Kitabistan', 'Bangladesh'),
  (11, 'Little Scholarz Books', 'India'),
  (12, 'Rupa Publications', 'India'),
  (13, 'Hodder And Stoughton', 'India'),
  (14, 'Charulipi Prokashon', 'Bangladesh'),
  (15, 'Sondhani Prokashoni', 'Bangladesh'),
  (16, 'Hawlder Prokashoni', 'Bangladesh'),
  (17, 'Henry Holt', 'America');

--
-- Indexes for dumped tables
--
--
-- Indexes for table `Author`
--
ALTER TABLE `Author` ADD PRIMARY KEY (`Author_ID`);

--
-- Indexes for table `Author_Book_Relationship`
--
ALTER TABLE `Author_Book_Relationship` ADD PRIMARY KEY (`Book_No`, `Author_ID`),
ADD KEY `Author_ID` (`Author_ID`);

--
-- Indexes for table `Book`
--
ALTER TABLE `Book` ADD PRIMARY KEY (`Book_No`);

--
-- Indexes for table `Book_Character_Relationship`
--
ALTER TABLE `Book_Character_Relationship` ADD PRIMARY KEY (`Character_ID`, `Book_No`),
ADD KEY `Book_No` (`Book_No`);

--
-- Indexes for table `Characters`
--
ALTER TABLE `Characters` ADD PRIMARY KEY (`Character_ID`);

--
-- Indexes for table `Publisher`
--
ALTER TABLE `Publisher` ADD PRIMARY KEY (`Publisher_ID`);

--
-- Constraints for dumped tables
--
--
-- Constraints for table `Author_Book_Relationship`
--
ALTER TABLE `Author_Book_Relationship` ADD CONSTRAINT `author_book_relationship_ibfk_1` FOREIGN KEY (`Book_No`) REFERENCES `Book` (`Book_No`),
ADD CONSTRAINT `author_book_relationship_ibfk_2` FOREIGN KEY (`Author_ID`) REFERENCES `Author` (`Author_ID`);

--
-- Constraints for table `Book_Character_Relationship`
--
ALTER TABLE `Book_Character_Relationship` ADD CONSTRAINT `book_character_relationship_ibfk_1` FOREIGN KEY (`Character_ID`) REFERENCES `Characters` (`Character_ID`),
ADD CONSTRAINT `book_character_relationship_ibfk_2` FOREIGN KEY (`Book_No`) REFERENCES `Book` (`Book_No`);

COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;

/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;

/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

CREATE TABLE
  `Book_Publisher_Relationship` (
    `Book_No` int (11) NOT NULL,
    `Publisher_ID` int (11) NOT NULL,
    `Price` int (11) DEFAULT NULL `No_of_Pages` int (11) DEFAULT NULL
  ) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_general_ci;

--
-- Dumping data for table `Book_Publisher_Relationship`
--
INSERT INTO
  `Book_Publisher_Relationship` (`Book_No`, `Publisher_ID`, `Price`, `No_of_Pages`)
VALUES
  (1, 1, 182, 134),
  (1, 2, 90, 78),
  (2, 3, 150, 156),
  (2, 4, 200, 193),
  (3, 3, 390, 720),
  (3, 2, 255, 704),
  (3, 4, 450, 668),
  (4, 3, 165, 134),
  (4, 5, 176, 184),
  (5, 6, 360, 264),
  (5, 7, 200, 193),
  (5, 4, 132, 95),
  (6, 8, 90, 64),
  (7, 8, 140, 110),
  (8, 8, 114, 80),
  (9, 9, 855, 645),
  (10, 9, 1133, 768),
  (11, 9, 180, 73),
  (11, 10, 123, 79),
  (12, 9, 180, 90),
  (12, 10, 90, 80),
  (13, 11, 233, 120),
  (14, 12, 270, 217),
  (15, 13, 450, 186),
  (16, 14, 298, 312),
  (16, 15, 255, 300),
  (17, 16, 225, 208),
  (18, 16, 375, 301),
  (19, 17, 390, NULL),
  (6, 15, 123, 80),
  (7, 15, 150, 112),
  (8, 14, 165, 100),
  (13, 13, 255, 150),
  (17, 12, 270, 184),
  (1, 3, 165, 112);

--
ALTER TABLE `Book_Publisher_Relationship` ADD PRIMARY KEY (`Publisher_ID`, `Book_No`),
ADD KEY `Book_No` (`Book_No`);