"""Exercise the recovered C body against the host string-search contract."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


class StrrchrTests(unittest.TestCase):
    def test_natural_c_matches_last_byte_search(self):
        source = (ROOT / 'src/dolphin/msl/tail_8008279C.c').read_text()
        match = re.search(r'^char\* __msl_strrchr\([^)]*\)\n\{[\s\S]*?\n\}', source, re.M)
        if match is None:
            self.fail('strrchr must have a natural-C definition')
        cc = shutil.which('cc')
        if cc is None:
            self.skipTest('host C compiler unavailable')
        harness = r'''
#include <string.h>
int main(void) {
    char storage[66];
    char *s = storage + 1;
    unsigned int state = 12345;
    int length, trial, c, i;
    for (length = 0; length <= 64; ++length) {
        for (trial = 0; trial < 32; ++trial) {
            for (i = 0; i < length; ++i) {
                state = state * 1664525u + 1013904223u;
                s[i] = (char)(1 + (state % 255));
            }
            s[length] = 0;
            for (c = -256; c <= 511; ++c) {
                if (__msl_strrchr(s, c) != strrchr(s, c)) return 1;
            }
        }
    }
    return 0;
}
'''
        with tempfile.TemporaryDirectory() as directory:
            p = Path(directory)
            (p / 'test.c').write_text(match.group() + '\n' + harness)
            subprocess.run([cc, '-std=c89', '-O2', str(p / 'test.c'), '-o', str(p / 'test')], check=True)
            subprocess.run([str(p / 'test')], check=True)


if __name__ == '__main__':
    unittest.main()
