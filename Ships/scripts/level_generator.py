import random

class TileFormat:
    def __init__(self, sprite_id, collision_type):
        self.sprite_id = sprite_id
        self.collision_type = collision_type

def app():
    row_tiles_count = input("Enter number of tiles in a row: ")
    column_tiles_count = input("Enter number of tiles in a column: ")
    map_name = input("Enter map name: ")
    maps_directory = "maps/"
    map_path = maps_directory + map_name

    with open(map_path, "w") as map_file:
        for j in range(int(column_tiles_count)):
            row = ""
            for i in range(int(row_tiles_count)):
                random_sprite_id = str(random.randint(0, 4))
                row = row + random_sprite_id + ":0 "
            map_file.write(row)
            map_file.write("\n")


if __name__ == '__main__':
    app()