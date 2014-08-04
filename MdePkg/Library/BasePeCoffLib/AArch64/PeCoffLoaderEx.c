/** @file
  Specific relocation fixups for ARM architecture.

  Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>
  Portions copyright (c) 2008 - 2010, Apple Inc. All rights reserved.<BR>
  Portions copyright (c) 2011 - 2013, ARM Ltd. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include "BasePeCoffLibInternals.h"
#include <Library/BaseLib.h>

// TODO AArch64 : Add relocations for small memory model. Currently only large
//                memory model is supported by UEFI relocation code.
//
//                This functionality also exists in the basetools at :
//                'edk2/BaseTools/Source/C/Common/PeCoffLoaderEx.c'

/**
  Performs an AARCH64-based specific relocation fixup and is a no-op on other
  instruction sets.

  @param  Reloc       The pointer to the relocation record.
  @param  Fixup       The pointer to the address to fix up.
  @param  FixupData   The pointer to a buffer to log the fixups.
  @param  Adjust      The offset to adjust the fixup.

  @return Status code.

**/
RETURN_STATUS
PeCoffLoaderRelocateImageEx (
  IN UINT16      *Reloc,
  IN OUT CHAR8   *Fixup,
  IN OUT CHAR8   **FixupData,
  IN UINT64      Adjust
  )
{
  // Currently all required runtime relocations are taken care of by common code.
  // We should not get here.
  return RETURN_UNSUPPORTED;
}

/**
  Returns TRUE if the machine type of PE/COFF image is supported. Supported
  does not mean the image can be executed it means the PE/COFF loader supports
  loading and relocating of the image type. It's up to the caller to support
  the entry point.

  @param  Machine   Machine type from the PE Header.

  @return TRUE if this PE/COFF loader can load the image

**/
BOOLEAN
PeCoffLoaderImageFormatSupported (
  IN  UINT16  Machine
  )
{
  if ((Machine == IMAGE_FILE_MACHINE_ARM64) || (Machine ==  IMAGE_FILE_MACHINE_EBC)) {
    return TRUE;
  }

  return FALSE;
}

/**
  Performs an ARM-based specific re-relocation fixup and is a no-op on other
  instruction sets. This is used to re-relocated the image into the EFI virtual
  space for runtime calls.

  @param  Reloc       The pointer to the relocation record.
  @param  Fixup       The pointer to the address to fix up.
  @param  FixupData   The pointer to a buffer to log the fixups.
  @param  Adjust      The offset to adjust the fixup.

  @return Status code.

**/
RETURN_STATUS
PeHotRelocateImageEx (
  IN UINT16      *Reloc,
  IN OUT CHAR8   *Fixup,
  IN OUT CHAR8   **FixupData,
  IN UINT64      Adjust
  )
{
  /* FIXME:  Does this work?? Taken from Itanium. Not sure if AArch64 platform can do this. */

  // Currently all required runtime relocations are taken care of by common code.
  // We should not get here.
  return RETURN_UNSUPPORTED;
}
