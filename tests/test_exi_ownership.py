"""Guard the EXI translation-unit split against stale merge tails."""
import re
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


class EXIOwnershipTests(unittest.TestCase):
    def test_initialize_uart_keeps_console_callback_signature(self):
        uart = (ROOT / 'src/dolphin/os/EXIUart.c').read_text()
        console = (ROOT / 'src/dolphin/msl/msl_80083E84.c').read_text()
        signature = r'int\s+InitializeUART\(unsigned long baud_rate\)'
        self.assertRegex(console, r'extern\s+' + signature + r';')
        self.assertRegex(uart, signature + r'\s*\{')

    def test_uart_functions_have_only_the_split_owner(self):
        for name in ('__EXIGetID', '__OSEnableBarnacle', 'InitializeUART', 'WriteUARTN'):
            pattern = re.compile(r'^\s*(?:asm\s+)?(?:int|void|u32)\s+' + name
                                 + r'\s*\([^;{}]*\)\s*\{', re.MULTILINE)
            owners = []
            for unit in ('EXIBios', 'EXIUart'):
                source = (ROOT / 'src/dolphin/os' / (unit + '.c')).read_text()
                owners.extend([unit] * len(pattern.findall(source)))
            with self.subTest(function=name):
                self.assertEqual(owners, ['EXIUart'])


if __name__ == '__main__':
    unittest.main()
