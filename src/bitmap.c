/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 11:56:57 by eruffieu          #+#    #+#             */
/*   Updated: 2015/06/03 15:09:33 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/rt.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

static void		write_file(t_libx *m, t_bitmap *pbitma, uint8_t *pixelbuffer)
{
	FILE		*fp;
	int			i;

	fp = fopen("screenshot.bmp","wb");
	fwrite (pbitma, 1, sizeof(t_bitmap),fp);
	i = 0;
	while (m->data[i])
	{
		pixelbuffer[i] = m->data[i];
		i++;
	}
	fwrite(pixelbuffer,1,PBS,fp);
	fclose(fp);
}


void			screenshot(t_libx *m)
{
	t_bitmap		*pbitma;
	uint8_t			*pixelbuffer;

	pbitma  = (t_bitmap*)calloc(1,sizeof(t_bitmap));
	pixelbuffer = (uint8_t*)malloc(PBS);
	strcpy((char *)pbitma->fileheader.signature, "BM");
	pbitma->fileheader.filesize = FILESIZE;
	pbitma->fileheader.fileoffset_to_pixelarray = sizeof(t_bitmap);
	pbitma->bitmapinfoheader.dibheadersize =sizeof(t_bitmapinfoheader);
	pbitma->bitmapinfoheader.width = WIDTH;
	pbitma->bitmapinfoheader.height = HEIGHT;
	pbitma->bitmapinfoheader.planes = PLANES;
	pbitma->bitmapinfoheader.bitsperpixel = BPP;
	pbitma->bitmapinfoheader.compression = COMPRESSION;
	pbitma->bitmapinfoheader.imagesize = PBS;
	pbitma->bitmapinfoheader.ypixelpermeter = YPPM;
	pbitma->bitmapinfoheader.xpixelpermeter = XPPM;
	pbitma->bitmapinfoheader.numcolorspallette = 0;
	write_file(m, pbitma, pixelbuffer);
	free(pbitma);
	free(pixelbuffer);
}