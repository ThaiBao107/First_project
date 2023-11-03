ALTER TABLE [dbo].[ThueSach]
ALTER COLUMN MaSach char(10)

exec sp_rename '[dbo].[ThueSach].GhiChu','Ghichu';

ALTER TABLE [dbo].[ThueSach]
ALTER COLUMN MaSach char(10) NOT NULL

ALTER TABLE [dbo].[ThueSach] ADD PRIMARY KEY(MaKH,MaSach,NgayMuon)

ALTER TABLE [dbo].[ThueSach] ADD FOREIGN KEY(MaSach)
REFERENCES [dbo].[BangSach](MaSach)		
