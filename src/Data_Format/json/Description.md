#Format description

```json
{
  "SERVICES" : [
    {
      "S_NAME" : "service name",
      "TESTS" : [
        {
          "T_NAME" : "test name",
          "NB_TEST" : 123,
          "ASSERTS" : [
            {
              "FILE" : "File name",  //#Present depending compilation option
              "LINE" : 123,  //#Present depending compilation option
              "A_NAME" : "assertion name",
              "TYPE" : "[UINT/INT/FLOAT/DOUBLE/STR]",
              "COMPARE" : "[EQUAL/NOT_EQUAL/HIGHER_THAN/LOWER_THAN/HIGHER_OR_EQUAL/LOWER_OR_EQUAL/FLAG_SET/NOT_FLAG_SET]",
              "EXPECTED" : "expected data",
              "OBTAINED" : "obtained data",
              "VALID" : "[OK/KO]"
            },
            {}
          ],
          "RESULT" : "[PASSED/FAILED]"
        }
      ]
    },
    {}
  ]
}
```