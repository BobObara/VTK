IF(NOT VTK_INSTALL_NO_RUNTIME)

  CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkfiltering.tcl.in
    ${CMAKE_CURRENT_BINARY_DIR}/vtkfiltering.tcl
    @ONLY)

  INSTALL(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/vtkfiltering.tcl
    DESTINATION ${VTK_TCL_INSTALL_DIR_CM24}/vtkfiltering
    COMPONENT RuntimeLibraries)
ENDIF(NOT VTK_INSTALL_NO_RUNTIME)
