test-case: server
    cmd: ../../../hdkmod.py -b actual test.hsl
    diff
        actual: actual.h
        expected: expected.h
    diff
        actual: actual.c
        expected: expected.c

test-case: server_methods
    cmd: ../../../hdkmod.py -b actual --server-methods test.hsl
    # Currently the server_methods.c file is not compared against an expected file

test-case: cpp_client
    cmd: ../../../hdkcli_cpp.py -b actual_client --module-name=actual_client_mod --no-inline test.hsl
    diff
        actual: actual_client.h
        expected: expected_client.h
    diff
        actual: actual_client.cpp
        expected: expected_client.cpp

test-case: cpp_client_inline
    cmd: ../../../hdkcli_cpp.py -b actual_client_inline --module-name=actual_client_mod test.hsl
    diff
        actual: actual_client_inline.h
        expected: expected_client_inline.h
    diff
        actual: actual_client_inline.cpp
        expected: expected_client_inline.cpp

test-case: dom
    cmd: ../../../hdkmod.py -b actual_dom --dom-schema test.hsl
    diff
        actual: actual_dom.h
        expected: expected_dom.h
    diff
        actual: actual_dom.c
        expected: expected_dom.c

test-case: cpp_client_dom
    cmd: ../../../hdkcli_cpp.py -b actual_client_dom --module-name=actual_client_dom_mod --dom-schema --no-inline test.hsl
    diff
        actual: actual_client_dom.h
        expected: expected_client_dom.h
    diff
        actual: actual_client_dom.cpp
        expected: expected_client_dom.cpp

test-case: wsdl
    cmd: ../../../hdkwsdl.py -b actual test.hsl
    diff
        actual: actual.wsdl
        expected: expected.wsdl

