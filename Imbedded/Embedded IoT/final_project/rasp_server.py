import websockets, asyncio

async def hello(websocket, path):
    print('server started...')
    while True :
        name = await websocket.recv()
        print(f'{name}을 받았습니다.')
        greeting = f'hello {name}'
        await websocket.send(greeting)
        print(f'{greeting}을 보냈습니다')
        
async def main():
    server = await websockets.serve(hello, host='70.12.226.249',port=4321)
    await asyncio.gather(server.wait_closed())

asyncio.run(main())    