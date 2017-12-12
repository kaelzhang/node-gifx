{
  'targets': [
    {
      'target_name': 'gifx',
      'sources': [
        'cc/Gifx.cc',
        'cc/bindings.cc'
      ],
      'include_dirs': [
        '<!(node -e "require(\'nan\')")'
      ],
      'dependencies': [
        '<(module_root_dir)/giflib/giflib.gyp:giflib'
      ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'conditions': [
          ['OS=="mac"', {
              'xcode_settings': {
                  'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
              }
          }]
      ]
    }
  ]
}
