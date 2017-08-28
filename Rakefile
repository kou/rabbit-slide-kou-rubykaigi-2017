require "rabbit/task/slide"

# Edit ./config.yaml to customize meta data

spec = nil
Rabbit::Task::Slide.new do |task|
  spec = task.spec
  spec.files += Dir.glob("images/**/*.*")
  # spec.files -= Dir.glob("private/**/*.*")
  spec.add_runtime_dependency("rabbit-theme-clear-code")
end

desc "Tag #{spec.version}"
task :tag do
  sh("git", "tag", "-a", spec.version.to_s, "-m", "Publish #{spec.version}")
  sh("git", "push", "--tags")
end

namespace :example do
  desc "Build Rubex example"
  task :rubex do
    cd("example/rubex") do
      sh("rubex", "fibonacci.rubex")
      cd("fibonacci") do
        ruby("execonf.rb")
        sh("make")
      end
    end
  end

  desc "Build JRuby example"
  task :jruby do
    cd("example/jruby") do
      sh("javac", "Fibonacci.java")
      sh("jar", "cf", "fibonacci.jar", "Fibonacci.class")
    end
  end
end
