# type: ignore
import pytest
import sys
import mock
import unittest
import os
import functionaltest


class test_Sample(unittest.TestCase):
    def test_sampleFcuntionA():
        returnvalue = functionaltest.sampleFcuntion(5, 0)
        print(returnvalue)

    def test_sampleFcuntionB():
        returnvalue = functionaltest.sampleFcuntion(10, 0)
        print(returnvalue)

    def test_sampleFcuntionC():
        returnvalue = functionaltest.sampleFcuntion(20, 0)
        print(returnvalue)
