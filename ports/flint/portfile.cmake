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
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/COPYING" "${SOURCE_PATH}/COPYING.LESSER")
