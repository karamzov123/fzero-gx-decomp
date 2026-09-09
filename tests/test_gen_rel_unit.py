from pathlib import Path
import tempfile
import unittest

from tools.gen_rel_unit import parse_functions, render


ASM = '''\
.include "macros.inc"
.text
.balign 4
.fn _prolog, global
/* 00000000 */\tblr
.endfn
.fn fn_13_0, global
/* 00000004 */\tlis r3, lbl_13_bss_0@ha
/* 00000004 */\tlis r4, gLanguageIndexTable@ha
.L_00000008:
/* 00000008 */\tbl r12
.endfn
.fn _epilog, global
/* 0000000C */\tblr
'''


class GenRelUnitTests(unittest.TestCase):
    def test_parser_and_renderer_retain_all_blocks_in_order(self):
        functions = parse_functions(ASM)
        self.assertEqual([name for name, _ in functions], ["_prolog", "fn_13_0", "_epilog"])
        output = render("replay", Path("auto_text.s"), functions)
        self.assertLess(output.index("asm void _prolog"), output.index("asm void fn_13_0"))
        self.assertLess(output.index("asm void fn_13_0"), output.index("asm void _epilog"))
        self.assertEqual(output.count("asm void "), 3)
        self.assertIn("extern unsigned char lbl_13_bss_0[];", output)
        self.assertIn("extern unsigned char gLanguageIndexTable[];", output)
        self.assertIn("lis r3, lbl_13_bss_0@ha", output)
        self.assertNotIn(".L_", output)

    def test_repeated_render_is_identical(self):
        functions = parse_functions(ASM)
        first = render("sample", Path("auto_text.s"), functions)
        second = render("sample", Path("auto_text.s"), parse_functions(ASM))
        self.assertEqual(first, second)

    def test_missing_fn_is_empty(self):
        self.assertEqual(parse_functions(".text\\n.balign 4\\n"), [])


if __name__ == "__main__":
    unittest.main()
