//
// Created by Gilian Joosen on 31/05/16.
//

#ifndef MENGHINDAR_DIRI_CUSTOMSCAN_H
#define MENGHINDAR_DIRI_CUSTOMSCAN_H

template <typename var_type>
void custom_scanf(const char * cstr, const char * pattern, var_type var1, var_type var2, var_type var3){
#ifdef __APPLE__
	sscanf(cstr, pattern, var1, var2, var3);
#else
	sscanf_s(cstr, pattern, var1, var2, var3);
#endif
}

#endif //MENGHINDAR_DIRI_CUSTOMSCAN_H
