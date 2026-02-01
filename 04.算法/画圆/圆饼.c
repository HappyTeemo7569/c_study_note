#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	size_t width; //宽
	size_t height; //高
	unsigned char *data; //数据
} Image;

//根据长宽创建图像，申请内存
static Image *
image_new(size_t width,
	size_t height)
{
	Image *image;

	image = malloc(sizeof *image);
	image->width = width;
	image->height = height;
	image->data = malloc(width * height * 3);

	return image;
}

//释放
static void
image_free(Image *image)
{
	free(image->data);
	free(image);
}

//填充图像
static void
image_fill(Image *image,
	unsigned char value)
{
	memset(image->data, value, image->width * image->height * 3);
}

//画点，正方形中点是圆心，比如（300,300）
static void
image_set_pixel(Image *image,
	size_t x,
	size_t y,
	unsigned char Rvalue,
	unsigned char Gvalue,
	unsigned char Bvalue)
{
	size_t tx, ty;
	unsigned char *p;

	tx = (image->width / 2) + x;
	ty = (image->height / 2) + y;

	p = image->data + (ty * image->width * 3) + tx * 3;
	// 从左上角开始拍，一个像素3位，y*总宽*3等于排了多少横行，x*3等于该排排了多少位。

	*p = Rvalue;
	*(p + 1) = Gvalue;
	*(p + 2) = Bvalue;
}

//写入文件
static void
image_save(const Image *image,
	const char *filename)
{
	FILE *out;

	out = fopen(filename, "wb");
	if (!out)
		return;

	fprintf(out, "P6\n");
	fprintf(out, "%zu %zu\n", image->width, image->height);
	fprintf(out, "255\n");

	fwrite(image->data, 1, image->width * image->height * 3, out);

	fclose(out);
}

//画圆
static void
draw_circle(Image *image,
	int radius,
	unsigned char Rvalue,
	unsigned char Gvalue,
	unsigned char Bvalue)
{
	int x, y;

	for (y = -radius; y <= radius; y++)
		for (x = -radius; x <= radius; x++)
			if ((x * x) + (y * y) <= (radius * radius))
				image_set_pixel(image, x, y, Rvalue, Gvalue, Bvalue);
}


int
main(int argc, char *argv[])
{
	Image *image;

	image = image_new(600, 600);

	image_fill(image, 0xff);
	draw_circle(image, 200, 0x00, 0x00, 0xff);
	image_save(image, "circle.ppm");

	image_free(image);

	return 0;
}
