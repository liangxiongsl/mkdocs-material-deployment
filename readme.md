## mkdocs一键部署工具 ##

### 使用方法 ###

1.	打开xmind生成"目录树"
2.	执行`稳定版-部署到指定目录.exe`
	1.	输入网站名
	2.	在自动打开的编辑器中，覆盖xmind生成的"目录树"(注意：最后一行留空；内容会自动覆盖到`/conf/nav.txt`文件中)
	3.	指定网站位于哪个目录

### conf/目录介绍 ###

- conf/目录存放所有基本的mkdocs配置文件

- nav.txt - 创建项目前必须配置的文件!!! 存放章节目录树的数据
- tree.txt - 存放项目目录树的数据

- mkdocs.yml - mkdocs最重要的配置文件
(其中故意去掉了site_name 和 nav的配置, 该项目会自动填充)
- extra.css - css基本配置
- extra.js - js基本配置

- main.html - 覆盖构建后项目目录的main.html，目前主要用于公告栏
- dict.txt - 字典(用于jieba插件)
- user_dict.txt - dict.txt

