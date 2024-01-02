{
  'targets': [
    {
      'target_name': 'dsa-native',
      'sources': [ 'src/linkedlist/vector-based/linkedlist.cc','src/linkedlist/pointer-based/linkedlist.cc',  'src/dsa.cc', 'src/error-handlers/*.cc','src/queue/queue.cc', 'src/stack/stack.cc', 'src/sorting-algorithms/quicksort.cc', 'src/sorting-algorithms/mergesort/mergesort.cc'],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.7'
      },
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      }, 
    }
  ]
}