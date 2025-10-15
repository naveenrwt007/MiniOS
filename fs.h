#ifndef FS_H
#define FS_H

void fs_init();
int fs_find(const char *name);
void fs_write(const char *name, const char *data);
void fs_read(const char *name);
void fs_list();
void fs_delete(const char *name);
void fs_info(const char *name);
void fs_edit(const char *name);
void fs_search(const char *keyword);
void fs_rename(const char *old_name, const char *new_name);
void fs_export_all();
void fs_clear_all();

#endif