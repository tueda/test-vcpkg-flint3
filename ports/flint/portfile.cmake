vcpkg_download_distfile(ARCHIVE
    URLS "https://github.com/flintlib/flint/releases/download/v${VERSION}/flint-${VERSION}.zip"
    FILENAME "flint-${VERSION}.zip"
    SHA512 2e8b62be1f43a93aa9e5a641ed053e51243a7488304c57b68411c748981e61fd541d355b9faadbd9215b3b92b4a541b7540aa826784c6db619bbcf78a9afe337
)

vcpkg_extract_source_archive(
    SOURCE_PATH
    ARCHIVE "${ARCHIVE}"
)

vcpkg_configure_make(
    SOURCE_PATH "${SOURCE_PATH}"
    AUTOCONFIG
)

vcpkg_install_make()
vcpkg_copy_pdbs()
vcpkg_fixup_pkgconfig()

# Patch flint.pc to ensure it links against GMP, MPFR and the standard math library.
file(READ "${CURRENT_PACKAGES_DIR}/lib/pkgconfig/flint.pc" _pc_content)
string(REPLACE
    "Libs: \"-L\${libdir}\" -lflint"
    "Libs: \"-L\${libdir}\" -lflint -lgmp -lmpfr -lm"
    _pc_content "${_pc_content}"
)
file(WRITE "${CURRENT_PACKAGES_DIR}/lib/pkgconfig/flint.pc" "${_pc_content}")

vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/COPYING" "${SOURCE_PATH}/COPYING.LESSER")
