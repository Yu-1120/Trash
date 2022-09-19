# autoUploadGithub

一个自动上传到github平台的qt程序

```
/AutoUploadGithub

```



看你提交日志

```
git log
```

---

查看本地仓库配置

```
git config --local --list
```

----

把本地库提交上去但是不去重

```
git add .  &&  git commit -m "update"  &&  git push  origin main
```

----

比如我在[Github](https://github.com/Alinvor) 上，新建了一个远程仓库(新建过程省略)；

我想以本地仓库为准，强制推送到远程仓库上去，且覆盖远程仓库

强制把本地仓库代码覆盖

```
git add .  && git commit -m "update" && git push -f --set-upstream origin main:main
```

---

拉取所有更新，不同步；

```
git fetch --all
```

**备注： 命令连接符 && 的意思是 前一条命令执行成功才执行后一条命令。**
**扩展：命令连接符 ;; 的意思是 不论前一条是否执行成功都继续执行后一条命令**。

## 拉取代码到本地，解决拉取代码时发生的文件冲突

```
git pull origin main
```



git push origin master:hb-dev 

将本地库与服务器上的库进行关联 
