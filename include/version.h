#ifndef VERSION_H
#define VERSION_H

/* Build version, as in configure.py VERSIONS (-DBUILD_VERSION). */
#define VERSION_USA 0 /* GFZE01 */
#define VERSION_PAL 1 /* GFZP01 */
#define VERSION_JPN 2 /* GFZJ01 */

#define VERSION BUILD_VERSION

/* The value for the version being built, at a place where the versions differ. */
#if VERSION == VERSION_USA
#define VERSION_SELECT(USA, PAL, JPN) (USA)
#elif VERSION == VERSION_PAL
#define VERSION_SELECT(USA, PAL, JPN) (PAL)
#elif VERSION == VERSION_JPN
#define VERSION_SELECT(USA, PAL, JPN) (JPN)
#else
#error "unknown BUILD_VERSION"
#endif

#endif
