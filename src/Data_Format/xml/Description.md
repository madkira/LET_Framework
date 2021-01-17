#Format description

##Generic format
```xml
<LET_RUN>
  <SERVICE S_NAME="service name" NB_TEST="123">
    <TEST T_NAME="test name">
      <ASSERT FILE="File name" LINE="0123" A_NAME="Assert name" TYPE="[UINT/INT/FLOAT/DOUBLE/STR]" COMPARE="[EQUAL/NOT_EQUAL/HIGHER_THAN/LOWER_THAN/HIGHER_OR_EQUAL/LOWER_OR_EQUAL/FLAG_SET/NOT_FLAG_SET]" EXPECTED="Expected value" OBTAINED="Obtained value" VALID="[OK/KO]"/>
      <ASSERT .../>
      .....
      <ASSERT .../>

      <RESULT>[PASSED/FAILED]</RESULT>
    </TEST>
    <TEST ...> ... </TEST>
    ...
    <TEST ...> ... </TEST>
  </SERVICE>
  <SERVICE ...> ... </SERVICE>
  ...
  <SERVICE ...> ... </SERVICE>
</LET_RUN>
```


##Exemple
Compilation parameter :
 * -DFILE_AND_LINE=ON
 * -DONLY_FAILED_ASSERT=OFF
 * -DSTOP_TEST_ON_FAILED=ON
```xml
<LET_RUN>
        <SERVICE S_NAME="mono" NB_TEST="1">
                <TEST T_NAME="mono_basic_assertion">
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="17" A_NAME="value" TYPE="UINT" COMPARE="EQUAL" EXPECTED="4294967295" OBTAINED="4294967295" VALID="OK"/>
                        <RESULT>PASSED</RESULT>
                </TEST>
        </SERVICE>
        <SERVICE S_NAME="dual" NB_TEST="2">
                <TEST T_NAME="mono_basic_assertion">
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="17" A_NAME="value" TYPE="UINT" COMPARE="EQUAL" EXPECTED="4294967295" OBTAINED="4294967295" VALID="OK"/>
                        <RESULT>PASSED</RESULT>
                </TEST>
                <TEST T_NAME="dual_basic_assertion">
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="27" A_NAME="value" TYPE="INT" COMPARE="EQUAL" EXPECTED="-9" OBTAINED="-9" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="28" A_NAME="value" TYPE="INT" COMPARE="NOT_EQUAL" EXPECTED="-9" OBTAINED="-9" VALID="KO"/>
                        <RESULT>FAILED</RESULT>
                </TEST>
        </SERVICE>
        <SERVICE S_NAME="multi" NB_TEST="3">
                <TEST T_NAME="mono_basic_assertion">
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="17" A_NAME="value" TYPE="UINT" COMPARE="EQUAL" EXPECTED="4294967295" OBTAINED="4294967295" VALID="OK"/>
                        <RESULT>PASSED</RESULT>
                </TEST>
                <TEST T_NAME="dual_basic_assertion">
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="27" A_NAME="value" TYPE="INT" COMPARE="EQUAL" EXPECTED="-9" OBTAINED="-9" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="28" A_NAME="value" TYPE="INT" COMPARE="NOT_EQUAL" EXPECTED="-9" OBTAINED="-9" VALID="KO"/>
                        <RESULT>FAILED</RESULT>
                </TEST>
                <TEST T_NAME="multi_basic_assertion">
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="52" A_NAME="uvalue" TYPE="UINT" COMPARE="EQUAL" EXPECTED="4294967295" OBTAINED="4294967295" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="53" A_NAME="uvalue" TYPE="UINT" COMPARE="LOWER_OR_EQUAL" EXPECTED="4294967295" OBTAINED="4294967295" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="54" A_NAME="uvalue" TYPE="UINT" COMPARE="HIGHER_OR_EQUAL" EXPECTED="4294967295" OBTAINED="4294967295" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="55" A_NAME="uvalue" TYPE="UINT" COMPARE="NOT_EQUAL" EXPECTED="4294967295" OBTAINED="4294967295" VALID="KO"/>
                        <RESULT>FAILED</RESULT>
                </TEST>
        </SERVICE>
        <SERVICE S_NAME="format" NB_TEST="4">
                <TEST T_NAME="uint_format_assertion">
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="74" A_NAME="u8value+3" TYPE="UINT" COMPARE="NOT_EQUAL" EXPECTED="0b11111111" OBTAINED="0b11111111" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="75" A_NAME="u8value+3" TYPE="UINT" COMPARE="NOT_EQUAL" EXPECTED="0c777" OBTAINED="0c377" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="76" A_NAME="u8value+3" TYPE="UINT" COMPARE="NOT_EQUAL" EXPECTED="0xFF" OBTAINED="0xFF" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="77" A_NAME="u8value+3" TYPE="UINT" COMPARE="NOT_EQUAL" EXPECTED="18446744073709551615" OBTAINED="255" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="80" A_NAME="u16value+3" TYPE="UINT" COMPARE="NOT_EQUAL" EXPECTED="0b1111111111111111" OBTAINED="0b1111111111111111" VALID="KO"/>
                        <RESULT>FAILED</RESULT>
                </TEST>
                <TEST T_NAME="uint_conversion_assertion">
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="101" A_NAME="u8value" TYPE="UINT" COMPARE="EQUAL" EXPECTED="0xFF" OBTAINED="0xFF" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="102" A_NAME="u8value" TYPE="UINT" COMPARE="NOT_EQUAL" EXPECTED="0xFFFF" OBTAINED="0xFFFF" VALID="KO"/>
                        <RESULT>FAILED</RESULT>
                </TEST>
                <TEST T_NAME="rename_assertion">
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="131" A_NAME="Rename uint assertion" TYPE="UINT" COMPARE="EQUAL" EXPECTED="0xFF" OBTAINED="0xFF" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="132" A_NAME="Rename int assertion" TYPE="INT" COMPARE="EQUAL" EXPECTED="26" OBTAINED="26" VALID="OK"/>
                        <RESULT>PASSED</RESULT>
                </TEST>
                <TEST T_NAME="str_assertion">
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="112" A_NAME="lorem_ipsum" TYPE="STR" COMPARE="EQUAL" EXPECTED="Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged." OBTAINED="Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged." VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="113" A_NAME="lorem_ipsum2" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged." OBTAINED="Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged!" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="114" A_NAME="lorem_ipsum3" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged." OBTAINED="Lorem Ipsum is simply dummy text of the printing and typesetting industry." VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="115" A_NAME="lorem_ipsum2" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="Lorem Ipsum is simply dummy text of the printing and typesetting industry." OBTAINED="Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged!" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="116" A_NAME="lorem_ipsum4" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged." OBTAINED="Lorem Ipsum is simply dummy text of the printing and typesetting industry!" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="117" A_NAME="lorem_ipsum2" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="Lorem Ipsum is simply dummy text of the printing and typesetting industry!" OBTAINED="Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged!" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="118" A_NAME="lorem_ipsum3" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="4C 6F 72 65 6D 20 49 70 73 75 6D 20 69 73 20 73 69 6D 70 6C 79 20 64 75 6D 6D 79 20 74 65 78 74 20 6F 66 20 74 68 65 20 70 72 69 6E 74 69 6E 67 20 61 6E 64 20 74 79 70 65 73 65 74 74 69 6E 67 20 69 6E 64 75 73 74 72 79 21 " OBTAINED="4C 6F 72 65 6D 20 49 70 73 75 6D 20 69 73 20 73 69 6D 70 6C 79 20 64 75 6D 6D 79 20 74 65 78 74 20 6F 66 20 74 68 65 20 70 72 69 6E 74 69 6E 67 20 61 6E 64 20 74 79 70 65 73 65 74 74 69 6E 67 20 69 6E 64 75 73 74 72 79 2E " VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="119" A_NAME="lorem_ipsum3" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="4C6F 7265 6D20 4970 7375 6D20 6973 2073 696D 706C 7920 6475 6D6D 7920 7465 7874 206F 6620 7468 6520 7072 696E 7469 6E67 2061 6E64 2074 7970 6573 6574 7469 6E67 2069 6E64 7573 7472 7921 " OBTAINED="4C6F 7265 6D20 4970 7375 6D20 6973 2073 696D 706C 7920 6475 6D6D 7920 7465 7874 206F 6620 7468 6520 7072 696E 7469 6E67 2061 6E64 2074 7970 6573 6574 7469 6E67 2069 6E64 7573 7472 792E " VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="120" A_NAME="lorem_ipsum3" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="4C6F7265 6D204970 73756D20 69732073 696D706C 79206475 6D6D7920 74657874 206F6620 74686520 7072696E 74696E67 20616E64 20747970 65736574 74696E67 20696E64 75737472 7921" OBTAINED="4C6F7265 6D204970 73756D20 69732073 696D706C 79206475 6D6D7920 74657874 206F6620 74686520 7072696E 74696E67 20616E64 20747970 65736574 74696E67 20696E64 75737472 792E" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="121" A_NAME="lorem_ipsum3" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="4C6F72656D204970 73756D2069732073 696D706C79206475 6D6D792074657874 206F662074686520 7072696E74696E67 20616E6420747970 6573657474696E67 20696E6475737472 7921" OBTAINED="4C6F72656D204970 73756D2069732073 696D706C79206475 6D6D792074657874 206F662074686520 7072696E74696E67 20616E6420747970 6573657474696E67 20696E6475737472 792E" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="123" A_NAME="lorem_ipsum3" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="01001100 01101111 01110010 01100101 01101101 00100000 01001001 01110000 01110011 01110101 01101101 00100000 01101001 01110011 00100000 01110011 01101001 01101101 01110000 01101100 01111001 00100000 01100100 01110101 01101101 01101101 01111001 00100000 01110100 01100101 01111000 01110100 00100000 01101111 01100110 00100000 01110100 01101000 01100101 00100000 01110000 01110010 01101001 01101110 01110100 01101001 01101110 01100111 00100000 01100001 01101110 01100100 00100000 01110100 01111001 01110000 01100101 01110011 01100101 01110100 01110100 01101001 01101110 01100111 00100000 01101001 01101110 01100100 01110101 01110011 01110100 01110010 01111001 00100001 " OBTAINED="01001100 01101111 01110010 01100101 01101101 00100000 01001001 01110000 01110011 01110101 01101101 00100000 01101001 01110011 00100000 01110011 01101001 01101101 01110000 01101100 01111001 00100000 01100100 01110101 01101101 01101101 01111001 00100000 01110100 01100101 01111000 01110100 00100000 01101111 01100110 00100000 01110100 01101000 01100101 00100000 01110000 01110010 01101001 01101110 01110100 01101001 01101110 01100111 00100000 01100001 01101110 01100100 00100000 01110100 01111001 01110000 01100101 01110011 01100101 01110100 01110100 01101001 01101110 01100111 00100000 01101001 01101110 01100100 01110101 01110011 01110100 01110010 01111001 00101110 " VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="124" A_NAME="lorem_ipsum3" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="0100110001101111 0111001001100101 0110110100100000 0100100101110000 0111001101110101 0110110100100000 0110100101110011 0010000001110011 0110100101101101 0111000001101100 0111100100100000 0110010001110101 0110110101101101 0111100100100000 0111010001100101 0111100001110100 0010000001101111 0110011000100000 0111010001101000 0110010100100000 0111000001110010 0110100101101110 0111010001101001 0110111001100111 0010000001100001 0110111001100100 0010000001110100 0111100101110000 0110010101110011 0110010101110100 0111010001101001 0110111001100111 0010000001101001 0110111001100100 0111010101110011 0111010001110010 0111100100100001 " OBTAINED="0100110001101111 0111001001100101 0110110100100000 0100100101110000 0111001101110101 0110110100100000 0110100101110011 0010000001110011 0110100101101101 0111000001101100 0111100100100000 0110010001110101 0110110101101101 0111100100100000 0111010001100101 0111100001110100 0010000001101111 0110011000100000 0111010001101000 0110010100100000 0111000001110010 0110100101101110 0111010001101001 0110111001100111 0010000001100001 0110111001100100 0010000001110100 0111100101110000 0110010101110011 0110010101110100 0111010001101001 0110111001100111 0010000001101001 0110111001100100 0111010101110011 0111010001110010 0111100100101110 " VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="125" A_NAME="lorem_ipsum3" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="01001100011011110111001001100101 01101101001000000100100101110000 01110011011101010110110100100000 01101001011100110010000001110011 01101001011011010111000001101100 01111001001000000110010001110101 01101101011011010111100100100000 01110100011001010111100001110100 00100000011011110110011000100000 01110100011010000110010100100000 01110000011100100110100101101110 01110100011010010110111001100111 00100000011000010110111001100100 00100000011101000111100101110000 01100101011100110110010101110100 01110100011010010110111001100111 00100000011010010110111001100100 01110101011100110111010001110010 0111100100100001" OBTAINED="01001100011011110111001001100101 01101101001000000100100101110000 01110011011101010110110100100000 01101001011100110010000001110011 01101001011011010111000001101100 01111001001000000110010001110101 01101101011011010111100100100000 01110100011001010111100001110100 00100000011011110110011000100000 01110100011010000110010100100000 01110000011100100110100101101110 01110100011010010110111001100111 00100000011000010110111001100100 00100000011101000111100101110000 01100101011100110110010101110100 01110100011010010110111001100111 00100000011010010110111001100100 01110101011100110111010001110010 0111100100101110" VALID="OK"/>
                        <ASSERT FILE="/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c" LINE="126" A_NAME="lorem_ipsum3" TYPE="STR" COMPARE="NOT_EQUAL" EXPECTED="0100110001101111011100100110010101101101001000000100100101110000 0111001101110101011011010010000001101001011100110010000001110011 0110100101101101011100000110110001111001001000000110010001110101 0110110101101101011110010010000001110100011001010111100001110100 0010000001101111011001100010000001110100011010000110010100100000 0111000001110010011010010110111001110100011010010110111001100111 0010000001100001011011100110010000100000011101000111100101110000 0110010101110011011001010111010001110100011010010110111001100111 0010000001101001011011100110010001110101011100110111010001110010 0111100100100001" OBTAINED="0100110001101111011100100110010101101101001000000100100101110000 0111001101110101011011010010000001101001011100110010000001110011 0110100101101101011100000110110001111001001000000110010001110101 0110110101101101011110010010000001110100011001010111100001110100 0010000001101111011001100010000001110100011010000110010100100000 0111000001110010011010010110111001110100011010010110111001100111 0010000001100001011011100110010000100000011101000111100101110000 0110010101110011011001010111010001110100011010010110111001100111 0010000001101001011011100110010001110101011100110111010001110010 0111100100101110" VALID="OK"/>
                        <RESULT>PASSED</RESULT>
                </TEST>
        </SERVICE>
</LET_RUN>
```