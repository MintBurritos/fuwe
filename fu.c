private byte[] readBmp(Bitmap image, ref int width, ref int height, ref int pitch)
{//将Bitmap锁定到系统内存中,获得BitmapData
BitmapData data = image.LockBits(new Rectangle(0, 0, image.Width, image.Height), ImageLockMode.ReadOnly, PixelFormat.Format24bppRgb);            
//位图中第一个像素数据的地址。它也可以看成是位图中的第一个扫描行
IntPtr ptr = data.Scan0;
 //定义数组长度
int soureBitArrayLength = data.Height * Math.Abs(data.Stride);
 byte[] sourceBitArray = new byte[soureBitArrayLength];
//将bitmap中的内容拷贝到ptr_bgr数组中
Marshal.Copy(ptr, sourceBitArray, 0, soureBitArrayLength);            width = data.Width;
height = data.Height;
pitch = Math.Abs(data.Stride);
