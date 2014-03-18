# push
for i in $(find . -type d -name 'libck*' | grep -v '^./.git'); do cd $i; git branch tmp; git checkout tmp; git add -A; git commit -m 'deps'; git checkout master; git merge tmp; git branch -D tmp; git fetch origin master; git push origin master; git pull origin master; cd -; done

for i in $(find . -type d -name 'libck*' | grep -v '^./.git'); do cd $i; git submodule init && git submodule update; cd -; done
