CREATE DATABASE QL_BangVideo
GO

USE QL_BangVideo
GO

CREATE TABLE BangBang
(
	MaBang char(10),
	TenBang nvarchar(50),
	TheLoai nvarchar(20),
	TenNuocSX nvarchar(20),
	GiaMua decimal(8,2),
	GhiChu nvarchar(MAX)
	CONSTRAINT key_MaBang_BangBang
	PRIMARY KEY(MaBang) 
)
GO


CREATE TABLE KhachHang
(
	MaKH int NOT NULL UNIQUE,
	TenKH nvarchar(50),
	DiaChi nvarchar(100),
	SDT nvarchar(12),
	TheLoaiYeuThich nvarchar(20),
	GhiChu nvarchar(MAX)
	CONSTRAINT key_MaKH_KhachHang
	PRIMARY KEY(MaKH)
)
GO

CREATE TABLE ThueBang
(
	MaKH int NOT NULL UNIQUE,
	MaBang char(10) NOT NULL,
	NgayThue datetime NOT NULL,
	NgayTra datetime,
	SoTienThu decimal(8,2),
	GhiChu nvarchar(MAX)
)
GO


ALTER TABLE ThueBang ADD PRIMARY KEY(MaKH,MaBang,NgayThue)


ALTER TABLE KhachHang ADD CONSTRAINT key_fore_ThueBach FOREIGN KEY(MaKH) 
REFERENCES ThueBang(MaKH)

ALTER TABLE ThueBang DROP CONSTRAINT key_fore_ThueBach

ALTER TABLE ThueBang ADD CONSTRAINT key_F_ThueBang FOREIGN KEY(MaBang)
REFERENCES BangBang(MaBang)