puts "请确保github(www.github.com)上已创建仓库"

print "请输入本地仓库路径："
path = gets.chomp
system("#{path[0..1]}")
system("cd #{path}")

print "请输入仓库名："
name = gets.chomp

system('git init')
system('git add .')
system('git commit -m "first commit"')
system("git remote add origin https://github.com/liangxiongsl/#{name}.git")
system('git branch -M main')
system('git push -u origin main')

system('mkdocs gh-deploy')
system('pause')
