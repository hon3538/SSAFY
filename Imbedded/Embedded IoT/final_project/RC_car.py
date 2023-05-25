# import asyncio, websockets

# async def hello():
#     url ="ws://70.12.226.249:4321"
#     async with websockets.connect(url) as websocket:
#         while True:
#             name = input ("name?")
            
#             await websocket.send(name)
#             print(f'{name} sent')
            
#             greeting = await websocket.recv()
#             print(f'{greeting} received.')

# async def main():
#     await asyncio.gather(hello())
    
# asyncio.run(main())
import asyncio, websockets

async def hello():
    url = "ws://70.12.226.249:4322"
    async with websockets.connect(url) as websocket:
        name = input("name?")
        await websocket.send(name)
        print(f'{name} sent')

        greeting = await websocket.recv()
        print(f'{greeting} received.')

asyncio.get_event_loop().run_until_complete(hello())
