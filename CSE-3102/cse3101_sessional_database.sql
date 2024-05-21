-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: May 13, 2024 at 07:14 AM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `cse3101 sessional`
--

-- --------------------------------------------------------

--
-- Table structure for table `Actor`
--

CREATE TABLE `Actor` (
  `Person_ID` int(11) NOT NULL,
  `Actor_Name` varchar(30) NOT NULL,
  `Birth_Year` year(4) NOT NULL,
  `No_Of_Films` int(11) NOT NULL,
  `No_Of_Awards` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `Actor`
--

INSERT INTO `Actor` (`Person_ID`, `Actor_Name`, `Birth_Year`, `No_Of_Films`, `No_Of_Awards`) VALUES
(4, 'Anjan Dutt', '1953', 39, 10),
(6, 'Goutam Ghose', '1950', 3, 1),
(7, 'Aparna Sen', '1945', 73, 43),
(8, 'Kaushik Ganguly', '1968', 22, 7),
(10, 'Soumitra chatterjee', '1935', 250, 220),
(11, 'Uttam Kumar', '1926', 190, 150),
(12, 'Razzak', '1942', 120, 100);

-- --------------------------------------------------------

--
-- Table structure for table `Director`
--

CREATE TABLE `Director` (
  `Person_ID` int(11) NOT NULL,
  `Director_Name` varchar(30) DEFAULT NULL,
  `Birth_Year` year(4) DEFAULT NULL,
  `No_Of_Films` int(11) DEFAULT NULL,
  `No_Of_Awards` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `Director`
--

INSERT INTO `Director` (`Person_ID`, `Director_Name`, `Birth_Year`, `No_Of_Films`, `No_Of_Awards`) VALUES
(1, 'Zahir Raihan', '1935', 5, 5),
(2, 'Rajkumar Hirani', '1962', 5, 9),
(3, 'Satyajit Ray', '1921', 45, 55),
(4, 'Anjan Dutta', '1953', 23, 17),
(5, 'Ritoparno Ghosh', '1963', 20, 15),
(6, 'Goutam Ghose ', '1950', 12, 8),
(7, 'Aparna Sen', '1945', 12, 7),
(8, 'Kaushik Ganguly', '1968', 23, 30);

-- --------------------------------------------------------

--
-- Table structure for table `Movie`
--

CREATE TABLE `Movie` (
  `Movie_ID` int(11) NOT NULL,
  `Movie_Name` varchar(30) DEFAULT NULL,
  `Genre` varchar(10) DEFAULT NULL,
  `Year` year(4) DEFAULT NULL,
  `IMDB_Rating` decimal(3,1) DEFAULT NULL,
  `Director_ID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `Movie`
--

INSERT INTO `Movie` (`Movie_ID`, `Movie_Name`, `Genre`, `Year`, `IMDB_Rating`, `Director_ID`) VALUES
(1, 'Pather Pachali', 'Drama', '1955', 8.5, 3),
(2, 'Noukadubi', 'Drama', '2011', 7.6, 5),
(3, 'Abohomaan', 'Drama', '2009', 7.3, 5),
(4, 'Joi Baba Felunath', 'Thriller', '1979', 8.0, 3),
(5, 'Jibon Theke Neya', 'Drama', '1970', 9.4, 1),
(6, 'Moner Manush', 'Biography', '2010', 8.0, 6),
(7, 'Apur Panchali', 'Biography', '2013', 8.2, 8),
(8, 'Goynae Bakhso', 'Comedy', '2013', 7.1, 7),
(9, 'Byomkesh O Agnibaan', 'Thriller', '2017', 7.4, 4),
(10, 'Byomkesh Bakshi', 'Thriller', '2010', 7.4, 4),
(11, 'PK', 'Fiction', '2014', 8.2, 2);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Actor`
--
ALTER TABLE `Actor`
  ADD PRIMARY KEY (`Person_ID`);

--
-- Indexes for table `Director`
--
ALTER TABLE `Director`
  ADD PRIMARY KEY (`Person_ID`);

--
-- Indexes for table `Movie`
--
ALTER TABLE `Movie`
  ADD PRIMARY KEY (`Movie_ID`),
  ADD KEY `movie director relation` (`Director_ID`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Movie`
--
ALTER TABLE `Movie`
  ADD CONSTRAINT `movie director relation` FOREIGN KEY (`Director_ID`) REFERENCES `Director` (`Person_ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
