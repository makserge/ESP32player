#include "convert_utf8_to_windows1251.h"

void convert_utf8_to_windows1251(const char* utf8, char* windows1251, size_t n)
{
	int i = 0;
	int j = 0;
	for (; i < (int)n && utf8[i] != 0; ++i) {
		char prefix = utf8[i];
		char suffix = utf8[i+1];
		if ((prefix & 0x80) == 0) {
			windows1251[j] = (char)prefix;
			++j;
		}
		else if ((~prefix) & 0x20) {
			int first5bit = prefix & 0x1F;
			first5bit <<= 6;
			int sec6bit = suffix & 0x3F;
			int unicode_char = first5bit + sec6bit;
			if (unicode_char >= 0x410 && unicode_char <= 0x44F) {
				windows1251[j] = (char)(unicode_char - 0x350);
			}
			else if (unicode_char >= 0x80 && unicode_char <= 0xFF) {
				windows1251[j] = (char)(unicode_char);
			}
			else if (unicode_char >= 0x402 && unicode_char <= 0x403) {
				windows1251[j] = (char)(unicode_char - 0x382);
			}
			else {
				int count = sizeof(g_letters) / sizeof(Letter);
				for (int k = 0; k < count; ++k) {
					if (unicode_char == g_letters[k].unicode) {
						windows1251[j] = g_letters[k].win1251;
						goto NEXT_LETTER;
					}
				}
				return;
			}
			NEXT_LETTER:
				++i;
				++j;
		}
		else {
			return;
		}
	}
	windows1251[j] = 0;
}




