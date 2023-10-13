drop database if exists Movie;
create database if not exists Movie;

-- SQL 명령어를 실행할 대상인 기본 데이터베이스를 Movie로 지정
use Movie;


CREATE TABLE Movie
(
  title varchar(25),
  year int,
  length int,
  inColor int,
  studioName varchar(15),
  producerC varchar(3) references MovieExec(cert),
  primary key (title, year)
);

  

CREATE TABLE MovieStar
(
  name varchar(30),
  address varchar(30),
  gender varchar(1),
  birthdate varchar(10),
  primary key (name)
);

  
  CREATE TABLE StarsIn 
(
  movieTitle varchar(30),
  movieYear int,
  starName varchar(30),
  PRIMARY KEY (movieTitle, movieYear, starName),
  FOREIGN KEY (starName) REFERENCES MovieStar(name),
  FOREIGN KEY (movieTitle, movieYear) REFERENCES Movie(title, year)
);

CREATE TABLE MovieExec
(
  name varchar(30),
  address varchar(30),
  cert int,
  netWorth int,
  primary key(cert)
);

CREATE TABLE Studio
(
  name varchar(30),
  address varchar(30),
  presC varchar(3) references MovieExec(cert),
  primary key(name)
);

  SET foreign_key_checks = 0; -- 외래키 체크 끄기
