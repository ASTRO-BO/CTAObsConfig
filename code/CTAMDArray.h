/***************************************************************************
 CTAMDArray.h
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

#ifndef _CTAMDARRAY_H
#define _CTAMDARRAY_H

#include <string>
#include <vector>
#include <ctautils/InputFileFITS.h>
#include "CTAMDTelescope.h"

namespace CTAConfig {
	/**
	 * A CTA Array Configuration
	 */
	class CTAMDArray {

	private:
		std::string arrayConfigName;
		std::string name;
		
		CTAUtils::InputFileFITS conf_file;
		
		///Array of strings that contain the following info: TELTYPEID TELTYPENAME CAMERATYPENAME MIRRORTYPENAME LOOKUP-TABLE-CONFIG-FILE
		std::vector < std::vector<std::string> > configArray;
		
	protected:
		
		void loadAdds(std::string filename);

	public:
		std::string getArrayConfigName();

		void setArrayConfigName(std::string arrayConfigName);

		CTAMDTelescope* getTelescope(int telID);
		
		CTAMDTelescopeType* getTelescopeType(int64_t telTypeID);

		
		/// Load Monte Carlo CTA Array Configuration
		/// \param name the name of the array
		/// \filenameArray the name of the .fits file that contains the configuration of the array
		/// \filenameAdditionalInfos the name of the file that contains the following info: TELTYPEID TELTYPENAME CAMERATYPENAME MIRRORTYPENAME LOOKUP-TABLE-CONFIG-FILE
		void loadConfig(std::string arrayName, std::string filenameArray, std::string filenameAdditionalInfos, std::string basedir);

		std::string getName();
		
	public:
		
		std::vector<CTAMDTelescope*> telescopes;
		std::vector<CTAMDTelescopeType*> telescopeTypes;
	};
}
#endif
