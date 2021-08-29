# LET_Framework

Light Embedded Testing Framework

![CI](https://github.com/madkira/LET_Framework/workflows/CI/badge.svg) [![codecov](https://codecov.io/gh/madkira/LET_Framework/branch/main/graph/badge.svg?token=C6TTPXTXQ9)](https://codecov.io/gh/madkira/LET_Framework)

## Description

This Testing framework is simply a way to normalise Test writing and result generating. It is made by providing a way to write Assertion that compare an expected value with the compute/obtained one.
This Assertions are organized in specific function that represent one Test. Usually the Test function contains the call to the function that is under test before calling assertions on the different values that need to be validated.
Also Tests are group by Service. A Service can represent the group of tests on Nominal case of use of a specific function.
The framework is also made to fit any way of outputing de results from standard printf/cout to direct memory write by requiring the definition of the framework printer function as you want/require ```void LET_Framework_printer (const char * data);```

## Component

### Assert

Assertion exist in 5 types __uint int float double str__ (float and double not yet implemented) and are with optional parameters to simplify the use of this assertions which require only 3 parameters :

* the comparaison type : EQUAL NOT_EQUAL HIGHER_THAN LOWER_THAN HIGHER_OR_EQUAL LOWER_OR_EQUAL FLAG_SET NOT_FLAG_SET
* the obtained variable which is used as default name for the assertion
* the expected value

Depending on the assetion type the optionals parameters changes and have differents purposes

#### UINT

```LET_ASSERT_UINT(COMPARE, OBTAINED, EXPECTED, PRECISION, FORMAT, NAME)```

* PRECISION : allow to define the number of bytes uint8_t to uint64_t
* FORMAT : permit to transform the print format from Binary or Hexadecimal
* NAME : rename the assertion for better test information

#### INT

```LET_ASSERT_INT(COMPARE, OBTAINED, EXPECTED, NAME)```

* NAME : rename the assertion for better test information

#### FLOAT

TODO

#### DOUBLE

TODO

#### STR

```LET_ASSERT_STR(COMPARE, OBTAINED, EXPECTED, WHITESPACE, FORMAT, NAME)```

* WHITESPACE : works only with specific format in order to space the data for non literal string
* FORMAT : permit to transform the print format from literal string to some sort of "DUMP memory like"
* NAME : rename the assertion for better test information

### Wrapper

#### Init function

```LET_INIT_TEST(name){instruction}```

This wrapper normalize the creation of initial function that is call prior of each test of the same Service. Allows further complience with potential framework evolution.

#### Test function

```LET_TEST(name){instruction}```

This wrapper normalize the creation of test function in order to not forgive the parameter *LET_Test \*itself* usetd by the framework. Allows further complience with potential framework evolution.

#### Call function

```LET_CALL_WRAP(expression);```

This wrapper normalize the call of the framework debug wrapper in order to have this output porperly handle. Allows further complience with potential framework evolution.

## Dependency

This framework only use the standard library for types "stdint.h"

## Compilation

### Generate the library

for standalone compilation of the framework as a library it require make and cmake
The generated library file is in ```build/lib```

```cmd
mkdir build
cd build
cmake ..
make
```

### Self test

#### compilation

```cmd
mkdir build
cd build
cmake -DBUILD_TESTING=ON -DFORMAT=JUNIT ..
make
```

#### execution

```cmd
./test/LET_FRAMEWORK_test
```

## Available configuration

### BUILD_TESTING

Compile the framework with the provided test code for self validation

Default if not specified _OFF_

```cnd
cmake -DBUILD_TESTING=[ON/OFF] ..
```

### FORMAT

Allow to change the printer format in order to facilitate the integration in the automation process available format JUNIT XML TEXT
JUNIT format force STOP_TEST_ON_FAILED and ONLY_FAILED_ASSERT to ON
There is also a CUSTOM format that is allowed if specific format is required and can be implemented inside the folder ```src/Data_Format/custom/``` \
*Default if not specified TEXT*

```cmd
cmake -DFORMAT=[XML/TEXT/CUSTOM] ..
```

### FILE_AND_LINE

Compile the framework with directive that add for each assertion it's \_\_FILE\_\_ and \_\_LINE\_\_ precompilation information\
*Default if not specified OFF*

```cmd
cmake -DFILE_AND_LINE=[ON/OFF] ..
```

### ONLY_FAILED_ASSERT

This directive force the framework to only print the failed assertions
This option if force to ON if the format is JUNIT \
*Default if not specified OFF*

```cmd
cmake -DONLY_FAILED_ASSERT=[ON/OFF] ..
```

### STOP_TEST_ON_FAILED

This directive force the framework to stop the current test and pass to the next one on the first failed assertion
This option if force to ON if the format is JUNIT \
*Default if not specified OFF*

```cmd
cmake -DSTOP_TEST_ON_FAILED=[ON/OFF] ..
```
