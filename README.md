# LET_Framework
Light Embedded Testing Framework

## Description
This Testing framework is simply a way to normalise Test writing and result generating. It is made by providing a way to write Assertion that compare an expected value with the compute/obtained one.
This Assertions are organized in specific function that represent one Test. Usually the Test function contains the call to the function that is under test before calling assertions on the different values that need to be validated.
Also Tests are group by Service. A Service can represent the group of tests on Nominal case of use of a specific function.
The framework is also made to fit any way of outputing de results from standard printf/cout to direct memory write by requiring the definition of the framework printer function as you want/require ```void LET_Framework_printer (const char * data);```


## Assert
Assertion exist in 5 types __uint int float double str__ (float and double not yet implemented) and are with optional parameters to simplify the use of this assertions which require only 3 parameters :
* the comparaison type : EQUAL NOT_EQUAL HIGHER_THAN LOWER_THAN HIGHER_OR_EQUAL LOWER_OR_EQUAL FLAG_SET NOT_FLAG_SET
* the obtained variable which is used as default name for the assertion
* the expected value

Depending on the assetion type the optionals parameters changes and have differents purposes
##### UINT
```ASSERT_UINT(COMPARE, OBTAINED, EXPECTED, PRECISION, FORMAT, NAME)```
* PRECISION : allow to define the number of bytes uint8_t to uint64_t
* FORMAT : permit to transform the print format from Binary or Hexadecimal
* NAME : rename the assertion for better test information
##### INT
```ASSERT_INT(COMPARE, OBTAINED, EXPECTED, NAME)```
* NAME : rename the assertion for better test information
##### FLOAT
TODO
##### DOUBLE
TODO
##### STR
```ASSERT_STR(COMPARE, OBTAINED, EXPECTED, WHITESPACE, FORMAT, NAME)```
* WHITESPACE : works only with specific format in order to space the data for non literal string
* FORMAT : permit to transform the print format from literal string to some sort of "DUMP memory like"
* NAME : rename the assertion for better test information

## Dependency
This framework only use the standard library for the type "stdint.h"

## Compilation

### Generate the library
for standalone compilation of the framework as a library it require make and cmake
The generated library file is in ```build/lib```
```
mkdir build
cd build
cmake ..
make
```

### Self test
##### compilation
```
mkdir build
cd build
cmake -DBUILD_TESTING=ON ..
make
```
##### execution
```
./test/LET_FRAMEWORK_test
```

## Available configuration
##### BUILD_TESTING
Compile the framework with the provided test code for self validation

Default if not specified _OFF_

```
cmake -DBUILD_TESTING=[ON/OFF] ..
```

##### FORMAT
Allow to change the printer format in order to facilitate the integration in the automation process available format XML TEXT
There is also a CUSTOM format that is allowed if specific format is required and can be implemented inside the folder ```src/Data_Format/custom/```

_Default if not specified TEXT_
```
cmake -DFORMAT=[XML/TEXT/CUSTOM] ..
```

##### FILE_AND_LINE
Compile the framework with directive that add for each assertion it's \_\_FILE__ and \_\_LINE__ precompilation information

_Default if not specified OFF_
```
cmake -DFILE_AND_LINE=[ON/OFF] ..
```

##### ONLY_FAILED_ASSERT
This directive force the framework to only print the failed assertions

_Default if not specified OFF_
```
cmake -DONLY_FAILED_ASSERT=[ON/OFF] ..
```

##### STOP_TEST_ON_FAILED
This directive force the framework to stop the current test and pass to the next one on the first failed assertion

_Default if not specified OFF_
```
cmake -DSTOP_TEST_ON_FAILED=[ON/OFF] ..
```

