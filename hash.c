#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_MAX_LEN	 1024
#define KEY_NAME_MAX_LEN 1024
#define KEY_TYPE_MAX_LEN 1024

struct Hash {
	void        *keys;
	char         types[KEY_TYPE_MAX_LEN][ARRAY_MAX_LEN];
	void        *vals[ARRAY_MAX_LEN];
	void        *(*get)(char key[KEY_NAME_MAX_LEN], struct Hash *self);
	int          (*set)(char key[KEY_NAME_MAX_LEN], char type[KEY_TYPE_MAX_LEN], void *value, struct Hash *self);
	unsigned int size;
};

void *get(char key[KEY_NAME_MAX_LEN], struct Hash *self) {
	for (int i = 0; i < self->size; i++) {
		char *_key = self->keys + (KEY_NAME_MAX_LEN * i);
		if (strncmp(_key, key, KEY_NAME_MAX_LEN) == 0) {
			return self->vals[i];
		}
	}
	return NULL;
}

// void *get (char key[ARRAY_MAX_LEN], struct Hash *self) {
// 	for (unsigned int i = 0; i < ARRAY_MAX_LEN; i++) {
// 		if (*self->keys[i] == '\0') return NULL;
// 		if (strncmp(self->keys[i], key, KEY_NAME_MAX_LEN) == 0) {
// 			return self->vals[i];
// 		}
// 	}
// 	return NULL;
// }

// void _set(char key[ARRAY_MAX_LEN], char type[ARRAY_MAX_LEN], void *value, struct Hash *self) {
// 	unsigned int i = self->size;
// 	memcpy(self->keys[i], key, KEY_NAME_MAX_LEN);
// 	memcpy(self->types[i], type, KEY_TYPE_MAX_LEN);
// 	self->vals[i]  = value;
// 	self->size = i + 1;
// }

// int set (char key[ARRAY_MAX_LEN], char type[ARRAY_MAX_LEN], void *value, struct Hash *self) {
// 	if (self->size > 0) {
// 		if (self->size > ARRAY_MAX_LEN) return -1;

// 		_set(key, type, value, self);
// 	} else {
// 		for (unsigned int i = 0; i < ARRAY_MAX_LEN; i++) {
// 			if (self->keys[i][0] == '\0') {
// 				_set(key, type, value, self);
// 				break;
// 			}
// 		}
// 	}

// 	return 0;
// }

int main () {
	int x = 5;
	char keys[2][KEY_NAME_MAX_LEN] = { "age", "boo" };
	struct Hash foo = {
		(void*)&keys,
		{{ "int" }},
		{ (void *) &x },
		get,
		NULL,
		2
	};

	printf("foo['age'] = %i\n", *((int *)foo.get("age", &foo)));
	printf("foo['boo'] = %s\n", ((char *)foo.get("boo", &foo)));
	printf("foo['boo'] = %s\n", ((char *)foo.get("bar", &foo)));

	// printf("foo['age'] = %i\n", *((int *)foo.get("age", &foo)));

	// char *name = "Mahmud";
	// foo.set("name", "string", (void *)name, &foo);

	// printf("foo['name'] = %s", (char *)foo.get("name", &foo));
	// char *read_name = foo.get("name", &foo);
	// int i = 0;
	// while (*(read_name + i) != '\0') {
	// 	printf("%c", *(read_name + i));
	// 	i = i + 1;
	// }

	// printf("\nfoo['bar'] = %s\n", ((char *)foo.get("bar", &foo)));

	return 0;
}
