-- phpMyAdmin SQL Dump
-- version 2.11.7
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: May 10, 2022 at 09:10 AM
-- Server version: 5.0.51
-- PHP Version: 5.2.6

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

--
-- Database: `new_database`
--
CREATE DATABASE `new_database` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `new_database`;

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE IF NOT EXISTS `customer` (
  `CustomerID` int(40) NOT NULL,
  `CustomerName` varchar(60) NOT NULL,
  `ContactNo` int(40) NOT NULL,
  `Location` varchar(60) NOT NULL,
  PRIMARY KEY  (`CustomerID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`CustomerID`, `CustomerName`, `ContactNo`, `Location`) VALUES
(81, 'Mr. ABC', 1785345647, 'Gazipur'),
(82, 'Miss. PQR', 1376452378, 'Uttara, Dhaka'),
(83, 'Miss. XYZ', 1564234565, 'Dhanmondi, Dhaka'),
(84, 'Mr. EFG', 1645347698, 'Gazipur'),
(85, 'Miss. IJK', 1723451759, 'Mirpur,Dhaka');

-- --------------------------------------------------------

--
-- Table structure for table `order_table`
--

CREATE TABLE IF NOT EXISTS `order_table` (
  `OrderID` int(40) NOT NULL,
  `CustomerID` int(40) NOT NULL,
  `EmployeeID` int(40) NOT NULL,
  `OrderDate` date NOT NULL,
  `ShipperID` int(40) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `order_table`
--

INSERT INTO `order_table` (`OrderID`, `CustomerID`, `EmployeeID`, `OrderDate`, `ShipperID`) VALUES
(1007, 84, 3, '2021-08-19', 12),
(1006, 76, 4, '2021-04-25', 7),
(1002, 83, 2, '2021-02-15', 15),
(1003, 81, 6, '2021-05-10', 1),
(1008, 56, 8, '2021-02-10', 3),
(1010, 77, 7, '2021-04-15', 3);

-- --------------------------------------------------------

--
-- Table structure for table `order_table_2`
--

CREATE TABLE IF NOT EXISTS `order_table_2` (
  `OrderID` int(40) NOT NULL,
  `CustomerID` int(40) NOT NULL,
  `EmployeeID` int(40) NOT NULL,
  `OrderDate` date NOT NULL,
  `ShipperID` int(40) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `order_table_2`
--

INSERT INTO `order_table_2` (`OrderID`, `CustomerID`, `EmployeeID`, `OrderDate`, `ShipperID`) VALUES
(1003, 81, 8, '2021-07-10', 3),
(1005, 77, 7, '2021-08-13', 8),
(1006, 56, 8, '2021-02-23', 5);
