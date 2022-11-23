import React, { createContext, useContext, useEffect, useState } from "react";

const Crypto = createContext()

export default function CryptoContext({ children }){
    const [currency, setCurrency] = useState("USD")
    const [symbol, setSymbol] = useState("$")

    useEffect(() => {
        if(currency === "INR") setSymbol("₹");
        else if(currency === "USD") setSymbol("$");
    }, [currency]);

    return (
        <div>
            <Crypto.Provider value={{currency, symbol, setCurrency}}>
                {children}
            </Crypto.Provider>
        </div>
    )
}

export function CryptoState (){
   return useContext(Crypto);
}