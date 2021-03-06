/***************************************************************************
 CTAMDCameraType.h
 -------------------
 copyright            : (C) 2014 Andrea Bulgarelli, Valentina Fioretti
 email                : bulgarelli@iasfbo.inaf.it, fioretti@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   and for public research institutes; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#ifndef _CTAMDCAMERATYPE_H
#define _CTAMDCAMERATYPE_H

#include <vector>
#include <string>
#include "CTAMDPixel.h"
#include "CTAGridMap.h"

namespace CTAConfig {

	class CTAMDCameraType {

	private:
		float cameraScaleFactor;
		float cameraCentreOffset;
		float cameraRotation;
		int camTypeID;
		std::string camTypeName;
		
		std::vector<uint16_t> row;
		std::vector<uint16_t> col;
		std::vector<int16_t> pix;
		
		CTAHexagonalPointyTopOddRowGridMap* map;

		

	public:
		
		CTAMDCameraType(int camTypeID, std::string camTypeName, float cameraScaleFactor, float cameraCentreOffset, float cameraRotation);
		
		void addPixel(CTAMDPixel* pixel);
		
		int getID();
		
		std::string getName();
		
		float getCameraScaleFactor();

		float getCameraCentreOffset();

		float getCameraRotation();

		int16_t getNpixels();
		
		CTAMDPixel* getPixel(int16_t pixelID);
		
		uint16_t loadGeometryLUT(std::string filename);
		
		/// -1 the pixel is not part of the geometry
		/// -2 out of index
		inline int16_t getGeometryLUTOffsetValue(int16_t row, int16_t col);
		
		inline uint16_t getGeometryLUTOffset_Nrows();
		
		inline uint16_t getGeometryLUTOffset_Ncols();
		
		
		CTAHexagonalPointyTopOddRowGridMap* getMap();
		
		
	public:
		
		std::vector<CTAMDPixel*> pixels;
		
		///lut loaded from file that contains the index to the array of data
		int16_t* lutOffset;
		
		uint16_t lutOffset_row;
		
		uint16_t lutOffset_col;

	};
}
#endif
