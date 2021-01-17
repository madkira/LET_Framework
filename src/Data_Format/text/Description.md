#Format description

##Generic format
```
Service Begin "service name" with 12345 test :
| Test Begin "test name"
| | Assertion [file name{l.12345}] "assertion name" : Expected [UINT/INT/FLOAT/DOUBLE/STR] [EQUAL/NOT_EQUAL/HIGHER_THAN/LOWER_THAN/HIGHER_OR_EQUAL/LOWER_OR_EQUAL/FLAG_SET/NOT_FLAG_SET] [expected value] Obtained [obtained value] --> [OK/KO]
| | Assertion ........
| | ........
| Test End "test name" : [PASSED/FAILED]
| Test Begin .........
| | .........
| Test End .........
| .........
Service End "service name"
Service Begin .........
| .........
Service End .........
.........
```


##Exemple
Compilation parameter :
 * -DFILE_AND_LINE=ON
 * -DONLY_FAILED_ASSERT=OFF
 * -DSTOP_TEST_ON_FAILED=ON
```
Service Begin "mono" with 1 test :
| Test Begin "mono_basic_assertion"
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.17}] "value" : Expected UINT EQUAL [4294967295] Obtained [4294967295] --> OK
| Test End "mono_basic_assertion" : PASSED
Service End "mono"
Service Begin "dual" with 2 tests :
| Test Begin "mono_basic_assertion"
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.17}] "value" : Expected UINT EQUAL [4294967295] Obtained [4294967295] --> OK
| Test End "mono_basic_assertion" : PASSED
| Test Begin "dual_basic_assertion"
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.27}] "value" : Expected INT EQUAL [-9] Obtained [-9] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.28}] "value" : Expected INT NOT_EQUAL [-9] Obtained [-9] --> KO
| Test End "dual_basic_assertion" : FAILED
Service End "dual"
Service Begin "multi" with 3 tests :
| Test Begin "mono_basic_assertion"
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.17}] "value" : Expected UINT EQUAL [4294967295] Obtained [4294967295] --> OK
| Test End "mono_basic_assertion" : PASSED
| Test Begin "dual_basic_assertion"
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.27}] "value" : Expected INT EQUAL [-9] Obtained [-9] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.28}] "value" : Expected INT NOT_EQUAL [-9] Obtained [-9] --> KO
| Test End "dual_basic_assertion" : FAILED
| Test Begin "multi_basic_assertion"
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.52}] "uvalue" : Expected UINT EQUAL [4294967295] Obtained [4294967295] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.53}] "uvalue" : Expected UINT LOWER_OR_EQUAL [4294967295] Obtained [4294967295] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.54}] "uvalue" : Expected UINT HIGHER_OR_EQUAL [4294967295] Obtained [4294967295] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.55}] "uvalue" : Expected UINT NOT_EQUAL [4294967295] Obtained [4294967295] --> KO
| Test End "multi_basic_assertion" : FAILED
Service End "multi"
Service Begin "format" with 4 tests :
| Test Begin "uint_format_assertion"
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.74}] "u8value+3" : Expected UINT NOT_EQUAL [0b11111111] Obtained [0b11111111] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.75}] "u8value+3" : Expected UINT NOT_EQUAL [0c777] Obtained [0c377] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.76}] "u8value+3" : Expected UINT NOT_EQUAL [0xFF] Obtained [0xFF] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.77}] "u8value+3" : Expected UINT NOT_EQUAL [18446744073709551615] Obtained [255] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.80}] "u16value+3" : Expected UINT NOT_EQUAL [0b1111111111111111] Obtained [0b1111111111111111] --> KO
| Test End "uint_format_assertion" : FAILED
| Test Begin "uint_conversion_assertion"
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.101}] "u8value" : Expected UINT EQUAL [0xFF] Obtained [0xFF] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.102}] "u8value" : Expected UINT NOT_EQUAL [0xFFFF] Obtained [0xFFFF] --> KO
| Test End "uint_conversion_assertion" : FAILED
| Test Begin "rename_assertion"
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.131}] "Rename uint assertion" : Expected UINT EQUAL [0xFF] Obtained [0xFF] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.132}] "Rename int assertion" : Expected INT EQUAL [26] Obtained [26] --> OK
| Test End "rename_assertion" : PASSED
| Test Begin "str_assertion"
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.112}] "lorem_ipsum" : Expected STR EQUAL [Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.] Obtained [Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.113}] "lorem_ipsum2" : Expected STR NOT_EQUAL [Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.] Obtained [Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged!] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.114}] "lorem_ipsum3" : Expected STR NOT_EQUAL [Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.] Obtained [Lorem Ipsum is simply dummy text of the printing and typesetting industry.] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.115}] "lorem_ipsum2" : Expected STR NOT_EQUAL [Lorem Ipsum is simply dummy text of the printing and typesetting industry.] Obtained [Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged!] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.116}] "lorem_ipsum4" : Expected STR NOT_EQUAL [Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.] Obtained [Lorem Ipsum is simply dummy text of the printing and typesetting industry!] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.117}] "lorem_ipsum2" : Expected STR NOT_EQUAL [Lorem Ipsum is simply dummy text of the printing and typesetting industry!] Obtained [Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged!] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.118}] "lorem_ipsum3" : Expected STR NOT_EQUAL [4C 6F 72 65 6D 20 49 70 73 75 6D 20 69 73 20 73 69 6D 70 6C 79 20 64 75 6D 6D 79 20 74 65 78 74 20 6F 66 20 74 68 65 20 70 72 69 6E 74 69 6E 67 20 61 6E 64 20 74 79 70 65 73 65 74 74 69 6E 67 20 69 6E 64 75 73 74 72 79 21 ] Obtained [4C 6F 72 65 6D 20 49 70 73 75 6D 20 69 73 20 73 69 6D 70 6C 79 20 64 75 6D 6D 79 20 74 65 78 74 20 6F 66 20 74 68 65 20 70 72 69 6E 74 69 6E 67 20 61 6E 64 20 74 79 70 65 73 65 74 74 69 6E 67 20 69 6E 64 75 73 74 72 79 2E ] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.119}] "lorem_ipsum3" : Expected STR NOT_EQUAL [4C6F 7265 6D20 4970 7375 6D20 6973 2073 696D 706C 7920 6475 6D6D 7920 7465 7874 206F 6620 7468 6520 7072 696E 7469 6E67 2061 6E64 2074 7970 6573 6574 7469 6E67 2069 6E64 7573 7472 7921 ] Obtained [4C6F 7265 6D20 4970 7375 6D20 6973 2073 696D 706C 7920 6475 6D6D 7920 7465 7874 206F 6620 7468 6520 7072 696E 7469 6E67 2061 6E64 2074 7970 6573 6574 7469 6E67 2069 6E64 7573 7472 792E ] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.120}] "lorem_ipsum3" : Expected STR NOT_EQUAL [4C6F7265 6D204970 73756D20 69732073 696D706C 79206475 6D6D7920 74657874 206F6620 74686520 7072696E 74696E67 20616E64 20747970 65736574 74696E67 20696E64 75737472 7921] Obtained [4C6F7265 6D204970 73756D20 69732073 696D706C 79206475 6D6D7920 74657874 206F6620 74686520 7072696E 74696E67 20616E64 20747970 65736574 74696E67 20696E64 75737472 792E] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.121}] "lorem_ipsum3" : Expected STR NOT_EQUAL [4C6F72656D204970 73756D2069732073 696D706C79206475 6D6D792074657874 206F662074686520 7072696E74696E67 20616E6420747970 6573657474696E67 20696E6475737472 7921] Obtained [4C6F72656D204970 73756D2069732073 696D706C79206475 6D6D792074657874 206F662074686520 7072696E74696E67 20616E6420747970 6573657474696E67 20696E6475737472 792E] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.123}] "lorem_ipsum3" : Expected STR NOT_EQUAL [01001100 01101111 01110010 01100101 01101101 00100000 01001001 01110000 01110011 01110101 01101101 00100000 01101001 01110011 00100000 01110011 01101001 01101101 01110000 01101100 01111001 00100000 01100100 01110101 01101101 01101101 01111001 00100000 01110100 01100101 01111000 01110100 00100000 01101111 01100110 00100000 01110100 01101000 01100101 00100000 01110000 01110010 01101001 01101110 01110100 01101001 01101110 01100111 00100000 01100001 01101110 01100100 00100000 01110100 01111001 01110000 01100101 01110011 01100101 01110100 01110100 01101001 01101110 01100111 00100000 01101001 01101110 01100100 01110101 01110011 01110100 01110010 01111001 00100001 ] Obtained [01001100 01101111 01110010 01100101 01101101 00100000 01001001 01110000 01110011 01110101 01101101 00100000 01101001 01110011 00100000 01110011 01101001 01101101 01110000 01101100 01111001 00100000 01100100 01110101 01101101 01101101 01111001 00100000 01110100 01100101 01111000 01110100 00100000 01101111 01100110 00100000 01110100 01101000 01100101 00100000 01110000 01110010 01101001 01101110 01110100 01101001 01101110 01100111 00100000 01100001 01101110 01100100 00100000 01110100 01111001 01110000 01100101 01110011 01100101 01110100 01110100 01101001 01101110 01100111 00100000 01101001 01101110 01100100 01110101 01110011 01110100 01110010 01111001 00101110 ] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.124}] "lorem_ipsum3" : Expected STR NOT_EQUAL [0100110001101111 0111001001100101 0110110100100000 0100100101110000 0111001101110101 0110110100100000 0110100101110011 0010000001110011 0110100101101101 0111000001101100 0111100100100000 0110010001110101 0110110101101101 0111100100100000 0111010001100101 0111100001110100 0010000001101111 0110011000100000 0111010001101000 0110010100100000 0111000001110010 0110100101101110 0111010001101001 0110111001100111 0010000001100001 0110111001100100 0010000001110100 0111100101110000 0110010101110011 0110010101110100 0111010001101001 0110111001100111 0010000001101001 0110111001100100 0111010101110011 0111010001110010 0111100100100001 ] Obtained [0100110001101111 0111001001100101 0110110100100000 0100100101110000 0111001101110101 0110110100100000 0110100101110011 0010000001110011 0110100101101101 0111000001101100 0111100100100000 0110010001110101 0110110101101101 0111100100100000 0111010001100101 0111100001110100 0010000001101111 0110011000100000 0111010001101000 0110010100100000 0111000001110010 0110100101101110 0111010001101001 0110111001100111 0010000001100001 0110111001100100 0010000001110100 0111100101110000 0110010101110011 0110010101110100 0111010001101001 0110111001100111 0010000001101001 0110111001100100 0111010101110011 0111010001110010 0111100100101110 ] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.125}] "lorem_ipsum3" : Expected STR NOT_EQUAL [01001100011011110111001001100101 01101101001000000100100101110000 01110011011101010110110100100000 01101001011100110010000001110011 01101001011011010111000001101100 01111001001000000110010001110101 01101101011011010111100100100000 01110100011001010111100001110100 00100000011011110110011000100000 01110100011010000110010100100000 01110000011100100110100101101110 01110100011010010110111001100111 00100000011000010110111001100100 00100000011101000111100101110000 01100101011100110110010101110100 01110100011010010110111001100111 00100000011010010110111001100100 01110101011100110111010001110010 0111100100100001] Obtained [01001100011011110111001001100101 01101101001000000100100101110000 01110011011101010110110100100000 01101001011100110010000001110011 01101001011011010111000001101100 01111001001000000110010001110101 01101101011011010111100100100000 01110100011001010111100001110100 00100000011011110110011000100000 01110100011010000110010100100000 01110000011100100110100101101110 01110100011010010110111001100111 00100000011000010110111001100100 00100000011101000111100101110000 01100101011100110110010101110100 01110100011010010110111001100111 00100000011010010110111001100100 01110101011100110111010001110010 0111100100101110] --> OK
| | Assertion [/home/belzebuth/workspace/perso/LET_Framework/test/main_test.c{l.126}] "lorem_ipsum3" : Expected STR NOT_EQUAL [0100110001101111011100100110010101101101001000000100100101110000 0111001101110101011011010010000001101001011100110010000001110011 0110100101101101011100000110110001111001001000000110010001110101 0110110101101101011110010010000001110100011001010111100001110100 0010000001101111011001100010000001110100011010000110010100100000 0111000001110010011010010110111001110100011010010110111001100111 0010000001100001011011100110010000100000011101000111100101110000 0110010101110011011001010111010001110100011010010110111001100111 0010000001101001011011100110010001110101011100110111010001110010 0111100100100001] Obtained [0100110001101111011100100110010101101101001000000100100101110000 0111001101110101011011010010000001101001011100110010000001110011 0110100101101101011100000110110001111001001000000110010001110101 0110110101101101011110010010000001110100011001010111100001110100 0010000001101111011001100010000001110100011010000110010100100000 0111000001110010011010010110111001110100011010010110111001100111 0010000001100001011011100110010000100000011101000111100101110000 0110010101110011011001010111010001110100011010010110111001100111 0010000001101001011011100110010001110101011100110111010001110010 0111100100101110] --> OK
| Test End "str_assertion" : PASSED
Service End "format"
````