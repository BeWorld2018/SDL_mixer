/* Ends of .ctors/.dtors: linked after every library (Makefile.mos), so
   these come last; the starts are in MIX_library.c (linked first). */
__asm("\n"
      ".pushsection \".ctors\",\"aw\",@progbits\n"
      ".globl __mos_ctors_end\n"
      "__mos_ctors_end:\n"
      ".popsection\n"
      ".pushsection \".dtors\",\"aw\",@progbits\n"
      ".globl __mos_dtors_end\n"
      "__mos_dtors_end:\n"
      ".popsection\n");
