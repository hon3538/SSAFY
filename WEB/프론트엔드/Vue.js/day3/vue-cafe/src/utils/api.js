import axios from "axios";

const DOMAIN = "http://13.125.243.79:8080";

const request = axios.create({
	baseURL: `${DOMAIN}/api`,
});





export const api = {
	menus: {
		// http://ssafy.o-r.kr:8080/api/menus 요청과 같다.
		findAll: () => request.get("/menus"),
		findOne: (id) => request.get(`/menus/${id}`),
		
		create: (name, description, file) => {
            //이미지 업로드 -> formData로 감싸서 보낸다
			const formData = new FormData();
			formData.append('name', name);
			formData.append('description', description);
			formData.append('file', file);
			return request.post(`/menus`, formData, {
				headers: {
					"Content-Type": "multipart/form-data"
				}
			})
		},
		// 메뉴 수정
		update: (id, name, description) => request.patch(`/menus/${id}`, {
			name: name,
			description
		}),
		// 메뉴 이미지 수정
		
		updateImage: (id, file) => {
			const formData = new FormData();
			formData.append('file', file)
			return request.post(`/menus/${id}/image`, formData, {
				headers: {
					"Content-Type": "multipart/form-data"
				}
			})
		},
		// 메뉴 삭제
		delete: (id) => request.delete(`/menus/${id}`)
	},

	
	orders: {
		// 주문목록 조회
		findAll: () => request.get("/orders"),
		// 주문 조회
		findOne: (id) => request.get(`/orders/${id}`),
		// 주문하기
		create: (menus_id, quantity, request_detail) => request.post(`/orders`, {
			menus_id,
			quantity,
			request_detail
		}),
		// 주문 내역 수정하기
		update: (id, menus_id, quantity, request_detail) => request.patch(`/orders/${id}`, {
			menus_id: menus_id,
			quantity,
			request_detail
		}),
		// 주문 내역 삭제하기 
		delete: (id) => request.delete(`/orders/${id}`)
	}
}





// export const api = {
// 	getAllMenus: () => request.get("/all_menus"),
// 	getAllMenusName: () => request.get("/all_menus_name"),
// 	getMenu: (menu_id) => request.get(`/menu/${menu_id}`),
// 	getAllOrders: () => request.get("/all_orders"),
// 	getOrder: (order_id) => request.get(`/order/${order_id}`),
// 	postOrder: (menu_id, menu_quantity, menu_order_detail = undefined) =>
// 		request.post("/order/", {
// 			menu_id,
// 			menu_quantity,
// 			menu_order_detail,
// 		}),
// 	patchOrder: (
// 		order_id,
// 		menu_id,
// 		menu_quantity,
// 		menu_order_detail = undefined
// 	) =>
// 		request.patch("/order", {
// 			order_id,
// 			menu_id,
// 			menu_quantity,
// 			menu_order_detail,
// 		}),
// 	deleteOrder: (order_id) => {
// 		return request.delete("/order", { data: { order_id } });
// 	},
// };
// 