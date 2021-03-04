#Format description

JUnit standard format reduice to minimal element due to limitations in the system

```xml
<?xml version="1.0" encoding="UTF-8"?>
<testsuites>
    <testsuite name="" <!-- Full (class) name of the test for non-aggregated testsuite documents.
                    Class name without the package for aggregated testsuites documents. Required -->
        tests=""     <!-- The total number of tests in the suite, required. -->
        >
        disabled=""  <!-- the total number of disabled tests in the suite. optional -->

        <!-- testcase can appear multiple times, see /testsuites/testsuite@tests -->
        <testcase name=""       <!-- Name of the test method, required. -->
            classname=""  <!-- Full class name for the class the test method is in. [Faked seens it is for c] required -->
            >

            <!-- Indicates that the test failed. A failure is a test which
            the code has explicitly failed by using the mechanisms for
            that purpose. For example via an assertEquals. Contains as
            a text node relevant data for the failure, e.g., a stack
            trace. optional -->
            <failure message="" <!-- The message specified in the assert. -->
                type=""    <!-- The type of the assert. -->
                ></failure>

        </testcase>
    </testsuite>
</testsuites>
```