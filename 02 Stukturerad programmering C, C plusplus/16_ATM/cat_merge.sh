#!/usr/local/bin/bash

export TEMP_FILE="_TEMP.cpp"
export OUTPUT_FILE="16_ATM_in_Cpp_Monolith_seludeft.cpp"
export INPUT_FILE_SRC="16_ATM_in_Cpp.cpp"
export INPUT_FILE_HDR="16_ATM_in_Cpp.h"

cat ${INPUT_FILE_HDR} >> ${TEMP_FILE}

echo -e "" >> ${TEMP_FILE}
echo -e "" >> ${TEMP_FILE}
echo -e "" >> ${TEMP_FILE}
echo -e "/* MERGE SPLIT */" >> ${TEMP_FILE}
echo -e "" >> ${TEMP_FILE}
echo -e "" >> ${TEMP_FILE}
echo -e "" >> ${TEMP_FILE}

cat ${INPUT_FILE_SRC} >> ${TEMP_FILE}

sed 's/#include\ \"16_ATM_in_Cpp.h\"/\/\/#include\ \"16_ATM_in_Cpp.h\"/g' ${TEMP_FILE} > ${OUTPUT_FILE}

rm ${TEMP_FILE}
