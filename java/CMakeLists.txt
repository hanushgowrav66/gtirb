#
# Cmake configuration for java build
#

include(UseJava)

# ---------------------------------------------------------------------------
# Getting dependencies (protobuf-java jar file)
# ---------------------------------------------------------------------------

file(
  DOWNLOAD
  https://repo1.maven.org/maven2/com/google/protobuf/protobuf-java/${Protobuf_VERSION}/protobuf-java-${Protobuf_VERSION}.jar
  ${CMAKE_CURRENT_BINARY_DIR}/protobuf-java-${Protobuf_VERSION}.jar
)

# ---------------------------------------------------------------------------
# Building the gtirb protobuf files into java
# ---------------------------------------------------------------------------

# Directory containing the *.class files generated from the *.proto files
set(GTIRB_PROTO_CLASS_DIR
    "${CMAKE_CURRENT_BINARY_DIR}/com/grammatech/gtirb/proto"
)

# Add commands to compile the *.proto files to *.class files
foreach(GTIRB_PROTO_FILE ${GTIRB_PROTO_FILES})
  get_filename_component(GTIRB_PROTO_BASENAME ${GTIRB_PROTO_FILE} NAME_WE)
  set(GTIRB_PROTO_CLASS_FILE
      ${GTIRB_PROTO_CLASS_DIR}/${GTIRB_PROTO_BASENAME}OuterClass.java
  )
  add_custom_command(
    OUTPUT ${GTIRB_PROTO_CLASS_FILE}
    COMMAND ${Protobuf_PROTOC_EXECUTABLE}
            --java_out=${CMAKE_CURRENT_BINARY_DIR}
            --proto_path=${GTIRB_PROTO_DIR} ${GTIRB_PROTO_FILE}
  )
  list(APPEND GTIRB_PROTOBUF_JAVA ${GTIRB_PROTO_CLASS_FILE})
endforeach()

# ---------------------------------------------------------------------------
# Building the gtirb java API
# ---------------------------------------------------------------------------

set(GTIRB_API_JAVAS
    AuxData
    Block
    ByteInterval
    CodeBlock
    DataBlock
    Directive
    Edge
    IR
    Module
    Node
    Offset
    ProxyBlock
    Section
    Serialization
    Symbol
    Util
)

foreach(GTIRB_API_JAVA ${GTIRB_API_JAVAS})
  list(
    APPEND
      GTIRB_API_SOURCES
      ${CMAKE_CURRENT_SOURCE_DIR}/com/grammatech/gtirb/${GTIRB_API_JAVA}.java
  )
endforeach()

set(GTIRB_API_JARFILE
    gtirb_api-${GTIRB_MAJOR_VERSION}.${GTIRB_MINOR_VERSION}.${GTIRB_PATCH_VERSION}
)
add_jar(${GTIRB_API_JARFILE} SOURCES ${GTIRB_API_SOURCES}
        ${GTIRB_PROTOBUF_JAVA} INCLUDE_JARS
        ${CMAKE_CURRENT_BINARY_DIR}/protobuf-java-${Protobuf_VERSION}.jar
)

# ---------------------------------------------------------------------------
# Building the test code
# ---------------------------------------------------------------------------

if(GTIRB_ENABLE_TESTS)

  if(WIN32)
    set(DIR_SEP "\;")
  else()
    set(DIR_SEP ":")
  endif()

  set(JAR_FILE_LIST
      "${GTIRB_API_JARFILE}.jar${DIR_SEP}protobuf-java-${Protobuf_VERSION}.jar"
  )

  add_custom_command(
    TARGET ${GTIRB_API_JARFILE}
    POST_BUILD
    COMMAND ${Java_JAVAC_EXECUTABLE} -cp ${JAR_FILE_LIST} -d
            ${CMAKE_CURRENT_BINARY_DIR}
            ${CMAKE_CURRENT_SOURCE_DIR}/tests/testIrSanity.java
    COMMENT "Building testIrSanity"
  )

  add_test(NAME JavaSanityTest
           COMMAND ${Java_JAVA_EXECUTABLE} -cp ".${DIR_SEP}${JAR_FILE_LIST}"
                   testIrSanity ${CMAKE_CURRENT_SOURCE_DIR}/tests/testIr.gtirb
  )

  set_tests_properties(
    JavaSanityTest PROPERTIES PASS_REGULAR_EXPRESSION "test OK."
  )

endif()
