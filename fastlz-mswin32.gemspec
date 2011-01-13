Gem::Specification.new do |spec|
  spec.name              = 'fastlz'
  spec.version           = '0.1.0'
  spec.platform          = 'mswin32'
  spec.summary           = 'Ruby bindings for FastLZ.'
  spec.require_paths     = %w(lib/i386-mswin32)
  spec.files             = Dir.glob('ext/*') + %w(lib/i386-mswin32/fastlz.so README)
  spec.author            = 'winebarrel'
  spec.email             = 'sgwr_dts@yahoo.co.jp'
  spec.homepage          = 'https://bitbucket.org/winebarrel/fastlz-ruby'
  spec.has_rdoc          = true
  spec.extra_rdoc_files  = %w(README ext/fastlz-ruby.c)
end
